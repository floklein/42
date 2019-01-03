# Roger-Skyline

Tutoriel pour le projet Roger-Skyline.

Contributeurs : Ftourret, Fleonard, Naplouvi


## PARTIE 1 : Creation de la VM

Téléchargez l'image Debian officielle :
```
https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-9.6.0-amd64-netinst.iso
```

Créez une machine debian de taille fixe de 8gb avec VirtualBox.

Installez l'image prédémment téléchargée de debian.

Avant de lancer la machine virtuelle. Dans VirtualBox, allez dans le gestionnaire de réseau de l'hôte (files->Host Network Manager ou CMD+W). 
Cliquez sur créer, puis décochez le serveur DHCP. Vous devriez avoir un hôte vboxnet0 avec l'ip 192.168.56.1/24.

Allez dans les paramètres de la machine Debian créée précedemment : Settings->network. 
Pour la carte 1, laissez le mode d'accès en NAT, puis activez la carte 2 en mode "Réseau hôte privé". 
Il sera par défaut sur vboxnet0.

Vous pouvez démarrer la VM.

A l'installation :

Créez une partition de 4.2Gb (en creation, creer une de *4.501gb*) avec / en mountpoint.

Puis une partition de de 1gb de type swap et enfin avec le reste du disque dur, faites une partition /home.

/!\ N'installez seulement que les services ssh et usuels (pas web ni environnement de bureau)

## PARTIE 2 : Jusqu'au ssh

Installez les packages nécessaires à Roger-Skyline :

```apt install -y vim sudo net-tools iptables-persistent fail2ban sendmail apache2```

Puis modifiez les paramètres ssh :

```vim /etc/ssh/sshd_config```

Modification du port en 2222 (ou autre mais restez cohérents dans le reste du projet) puis décommentez la ligne PasswordAuthentification yes.
Décommentez #PermitRootLogin prohibit-password et remplacez par No.
Décommentez #PubkeyAuthentication yes

Créez maintenant une nouvelle interface réseau qui fera le lien entre votre machine et votre host.

```vim /etc/network/interfaces```

Et ajoutez le contenu suivant : 

```
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).

source /etc/network/interfaces.d/*

# The loopback network interface
auto lo
iface lo inet loopback

# The primary network interface
allow-hotplug enp0s3
iface enp0s3 inet dhcp

allow-hotplug enp0s8
iface enp0s8 inet static
address 192.168.56.3
netmask 255.255.255.252
```

Créez maintenant un nouvel utilisateur :

```adduser username```

Entrez les infos puis ajoutez le au groupe sudo :

```adduser username sudo```

Redémarrez maintenant la machine : ```reboot```

Dans un terminal de votre host, générez une clé ssh publique :

```ssh-keygen``` 

Puis ```cat ~/.ssh/id_rsa.pub``` et copiez le contenu en entier.

Connectez vous mainteant à votre machine :

```ssh user@IPMACHINE -p 2222```

Entrez le mot de passe (obligatoire la première fois) et créez le dossier .ssh dans le home de votre utilsiateur :

```mkdir .ssh```

Collez ensuite la clé dans ```.ssh/authorized_keys```

Puis modifiez à nouveau le fichier de configuration ssh :

```sudo vim /etc/ssh/sshd_config``` et passez "PasswordAuthentification yes" à no.

Relancez le service ssh : ```sudo service ssh restart```

Sortez du ssh avec ```exit``` et retentez une connexion avec la commande prédédente. La connexion se fait désormais sans mot de passe avec les PublicKeys. Vous retrouverez votre VM dans le fichier .ssh/known_hosts.

## PARTIE 3 : Firewall

La partie Firewall se fait via des règles iptables.
Vous pouvez lister les règles existentes avec :

```sudo iptables -L```

Il n'y a pour l'instant aucune règles. Ajoutez donc le fichier ```sudo vim /etc/network/if-pre-up.d/iptables```

Dans ce fichier ajoutez les lignes suivantes : 

```
#!/bin/bash

iptables-restore < /etc/iptables.test.rules

iptables -F
iptables -X
iptables -t nat -F
iptables -t nat -X
iptables -t mangle -F
iptables -t mangle -X

iptables -P INPUT DROP

iptables -P OUTPUT DROP

iptables -P FORWARD DROP

iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT

iptables -A INPUT -p tcp -i enp0s8 --dport 2222 -j ACCEPT

iptables -A INPUT -p tcp -i enp0s8 --dport 80 -j ACCEPT

iptables -A INPUT -p tcp -i enp0s8 --dport 443 -j ACCEPT

iptables -A OUTPUT -m conntrack ! --ctstate INVALID -j ACCEPT

iptables -I INPUT -i lo -j ACCEPT

iptables -A INPUT -j LOG

iptables -A FORWARD -j LOG

iptables -I INPUT -p tcp --dport 80 -m connlimit --connlimit-above 10 --connlimit-mask 20 -j DROP

exit 0
```

Puis rendez ce fichier executable.

```sudo chmod+x /etc/network/if-pre-up.d/iptables```

Les règles iptables sont remises à zéro à chaque reboot. 
Ce fichier permettra au packet iptables-persistent de charger vos règles à chaque redémarrage. 
Modifiez le port 2222 par le port de votre ssh.


## PARTIE 4 : DOS

Créez un fichier de log pour votre serveur Apache.

```sudo touch /var/log/apache2/server.log```

Le packet fail2ban intègre des protections contre les attaques courantes. Il suffit de les activer en créant un fichier de configuration local. Cela permet de ne pas modifier directement les jails par défaut de jail.conf.

```sudo vim /etc/fail2ban/jail.local```

Puis ajoutez les jails suivantes : 

```
[DEFAULT]
destemail = USER@student.le-101.fr
sender = root@roger-skyline.fr

[sshd]
port = 2222
enabled = true
maxretry = 5
findtime = 120
bantime = 60

[sshd-ddos]
port = 2222
enabled = true

[recidive]
enabled = true

[apache]
enabled = true
port = http, https
filter = apache-auth
logpath = /var/log/apache2*/*error.log
maxretry = 6
findtime = 600

[apache-noscript]
enabled = true

[apache-overflows]

enabled  = true
port     = http,https
filter   = apache-overflows
logpath  = /var/log/apache2*/*error.log
maxretry = 2

[apache-badbots]

enabled  = true
port     = http,https
filter   = apache-badbots
logpath  = /var/log/apache2*/*error.log
maxretry = 2

[http-get-dos]
enabled = true
port = http,https
filter = http-get-dos
logpath = /var/log/apache2/server.log
maxretry = 100
findtime = 300
bantime = 300
action = iptables[name=HTTP, port=http, protocol=tcp]
```

Créez également le fichier suivant :

```sudo vim /etc/fail2ban/filter.d/http-get-dos.conf``` avec pour contenu :

```
[Definition]

# Option: failregex
# Note: This regex will match any GET entry in your logs, so basically all valid and not valid entries are a match.
# You should set up in the jail.conf file, the maxretry and findtime carefully in order to avoid false positives.

failregex = ^<HOST> -.*"(GET|POST).*

# Option: ignoreregex
# Notes.: regex to ignore. If this regex matches, the line is ignored.
# Values: TEXT
#
ignoreregex =
```

Relancer ensuite le service fail2ban : ```sudo systemctl restart fail2ban.service```

Si pas d'erreur, tout va bien. Un ```iptables -L``` liste désormais de nouvelles règles en plus des prédédentes.

## PARTIE 5 : scan des ports

La commande ```sudo netstat -paunt``` devrait lister les ports ouverts de votre machine.
Assurez que seuls ceux que vous utilisez dans le projet soient ouverts.

## PARTIE 6 : services inutiles

```
systemctl list-unit-files

systemctl disable <services inutiles>
```

## PARTIE 7 : script d'update

Créez le script :

```vim /home/USER/update_script.sh```

```
#! /bin/bash
apt-get update && apt-get upgrade
```

Rendez le exécutable :

```chmod +x update_script.sh```

Puis ajoutez le dans ```sudo vim /etc/crontab``` :

```
0 4	* * 1	root	/home/USER/update_script.sh  >> /var/log/update_script.log
@reboot		root	/home/USER/update_script.sh  >> /var/log/update_script.log
```

## PARTIE 8 : Script de surveillance

Créez une copie de votre crontab actuel :

```cp /etc/crontab /home/USER/tmp```

Créez le template du mail que vous enverrez :

```vim /home/USER/email.txt```

Remplir le contenu du fichier email.txt avec le message que vous souhaitez.
Puis créez le script :

```vim /home/USER/watch_script.sh```

```
#!/bin/bash
cat /etc/crontab > /home/USER/new
DIFF=$(diff new tmp)
if [ "$DIFF" != "" ]; then
	sudo sendmail ROOT@MAIL.com < /home/USER/email.txt
	rm -rf /home/USER/tmp
	cp /home/USER/new /home/USER/tmp
fi
```

Rendez-le exécutable :

```chmod +x watch_script.sh```

Ajoutez le ensuite à votre crontab :

```sudo vim /etc/crontab```
```
0  0	* * *	root	/home/USER/watch_script.sh
```

Le mail sera envoyé à l'adresse renseignée.

## PARTIE 9 : Partie web

Générez une nouvelle clé SSL :

```sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/roger-skyline.com.key -out /etc/ssl/certs/roger-skyline.com.crt```

Rentrez les infos quand demandées.

Puis : 

```sudo vim /etc/apache2/sites-available/default-ssl.conf```

Et modifiez uniquement les lignes SSL en renseignant le bon chemin des clés (les deux lignes sous SSLEngine on) :

```
<IfModule mod_ssl.c>
 <VirtualHost _default_:443>       
                ServerAdmin webmaster@localhost
                DocumentRoot /var/www/html

                ErrorLog ${APACHE_LOG_DIR}/error.log
                CustomLog ${APACHE_LOG_DIR}/access.log combined

                #Include conf-available/serve-cgi-bin.conf

                #   SSL Engine Switch:
                #   Enable/Disable SSL for this virtual host.
                SSLEngine on
                SSLCertificateFile      /etc/ssl/certs/roger-skyline.com.crt
                SSLCertificateKeyFile /etc/ssl/private/roger-skyline.com.key
                #
                #SSLCertificateFile      /etc/ssl/certs/ssl-cert-snakeoil.pem
                #SSLCertificateKeyFile /etc/ssl/private/ssl-cert-snakeoil.key

......................
.......................

 </VirtualHost>
</IfModule>
```

Puis testez les commandes suivantes :

```
sudo apachectl configtest
sudo a2enmod ssl
sudo a2ensite default-ssl
```

Si pas de message d'erreur, on peut redémarrer le service :

```sudo systemctl restart apache2.service```

Faites ensuite une copie de la configuration par défaut :

```sudo cp /etc/apache2/sites-available/000-default.conf /etc/apache2/sites-available/001-default.conf```

Et modifiez le fichier ```sudo vim /etc/apache2/sites-available/001-default.conf```

Changez le ServerName par ce que vous voulez et le DocumentRoot par le chemin vers votre site web.

Activez la nouvelle configuration :

```
# Désactive l'ancienne configuration
a2dissite 000-default.conf
# Active la nouvelle
a2ensite 001-site.conf
# La commande parle d'elle-même...
systemctl reload apache2
```

Le site sera normalement accessible sur votre IP (https://192.168.56.3). 
C'est un certificat auto signé donc le navigateur vous mettra un avertissement avant d'y accéder.

Vous pouvez mettre les fichiers de votre site dans le dossier /var/www/html si vous n'avez pas changé le DocumentRoot.

Tips : un ```sudo chown -R /var/www/html``` peut s'avérer très pratique.


## PARTIE 10 : Partie deploiement

Soyez créatifs :)
