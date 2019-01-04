# Roger-Skyline-1

```bash
$ apt install -y vim sudo net-tools iptables-persistent fail2ban sendmail exim4 apache2
```

## 1. SSH

```bash
$ vim /etc/ssh/sshd_config
```

Éditer :

> Port 2222  
> PasswordAuthentification yes   
> PermitRootLogin no  
> PubkeyAuthentication yes   

### Création d'une interface réseau

```bash
$ vim /etc/network/interfaces
```

Éditer :

> allow-hotplug enp0s8  
> iface enp0s8 inet static  
> address 192.168.56.3  
> netmask 255.255.255.252  

### Clé publique SSH
(as *root*)

```bash
$ ssh-keygen
```

Copier :
```bash
$ cat ~/.ssh/id_rsa.pub
```

```bash
$ ssh flklein@debian -p 2222
```

(as *flklein*)

```bash
$ mkdir .ssh
```

Coller dans :
```bash
$ vi ~/.ssh/authorized_keys
```

(as *root*)

```bash
$ sudo vim /etc/ssh/sshd_config
```

Éditer :

> PasswordAuthentification no

```bash
$ sudo service ssh restart
```

(as *flklein*)
```bash
$ cat ~/.ssh/known_hosts
```

## 2. Firewall

```bash
$ sudo iptables -L
```

### Création de règles

```bash
$ sudo vim /etc/network/if-pre-up.d/iptables
```

Éditer :

> #!/bin/bash  
> 
> iptables-restore < /etc/iptables.test.rules  
> 
> iptables -F  
> iptables -X  
> iptables -t nat -F  
> iptables -t nat -X  
> iptables -t mangle -F  
> iptables -t mangle -X  
> 
> iptables -P INPUT DROP  
> iptables -P OUTPUT DROP  
> iptables -P FORWARD DROP  
> 
> iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT  
> iptables -A INPUT -p tcp -i enp0s8 --dport 2222 -j ACCEPT  
> iptables -A INPUT -p tcp -i enp0s8 --dport 80 -j ACCEPT  
> iptables -A INPUT -p tcp -i enp0s8 --dport 443 -j ACCEPT  
> iptables -A OUTPUT -m conntrack ! --ctstate INVALID -j ACCEPT  
> 
> iptables -I INPUT -i lo -j ACCEPT  
> iptables -A INPUT -j LOG  
> iptables -A FORWARD -j LOG  
> 
> iptables -I INPUT -p tcp --dport 80 -m connlimit --connlimit-above 10 --connlimit-mask 20 -j DROP  
> 
> exit 0  

```bash
$ sudo chmod+x /etc/network/if-pre-up.d/iptables
```

## 3. DOS

```bash
$ sudo touch /var/log/apache2/server.log
```

### Règles fail2ban

```bash
$ sudo vim /etc/fail2ban/jail.local
```

Éditer :

> [DEFAULT]  
> destemail = flklein@student.42.fr  
> sender = root@debian  
> 
> [sshd]  
> port = 2222  
> enabled = true  
> maxretry = 5  
> findtime = 120  
> bantime = 60  
> 
> [sshd-ddos]  
> port = 2222  
> enabled = true  
> 
> [recidive]  
> enabled = true  
> 
> [apache]  
> enabled = true  
> port = http, https  
> filter = apache-auth  
> logpath = /var/log/apache2*/*error.log  
> maxretry = 6  
> findtime = 600  
> 
> [apache-noscript]  
> enabled = true  
> 
> [apache-overflows]  
> 
> enabled = true  
> port = http, https  
> filter = apache-overflows  
> logpath = /var/log/apache2*/*error.log  
> maxretry = 2  
> 
> [apache-badbots]  
> 
> enabled = true  
> port = http,https  
> filter = apache-badbots  
> logpath = /var/log/ap ache2*/*error.log  
> maxretry = 2  
> 
> [http-get-dos]  
> enabled = true  
> port = http, https  
> filter = http-get-dos  
> logpath = /var/log/apache2/server.log  
> maxretry = 100  
> findtime = 300  
> bantime = 300  
> action = iptables[name=HTTP, port=http, protocol=tcp]  

### Filtres fail2ban

```bash
$ sudo vim /etc/fail2ban/filter.d/http-get-dos.conf
```

Éditer :

> [Definition]  
> 
> #Option: failregex  
> #Note: Matches GET and POST  
> 
> failregex = ^<HOST> -.\*"(GET|POST).\*  
> 
> #Option: ignoreregex  
> #Notes.: Ignores specific regex  
> #Values: TEXT  
> 
> ignoreregex =  

```bash
$ sudo systemctl restart fail2ban.service
```

```bash
$ iptables -L
```

## 4. Ports

```bash
$ sudo netstat -paunt
```

## 5. Services

```bash
$ systemctl list-unit-files
$ systemctl disable <services inutiles>
```

## 6. Script update

```bash
$ vim /home/flklein/update_script.sh
```

Éditer :

> #!/bin/bash  
> apt-get update && apt-get upgrade  

```bash
$ chmod +x update_script.sh
```

### Ajout à crontab

```bash
$ sudo vim /etc/crontab
```

Éditer :

> 0 4	* * 1	root	/home/flklein/update_script.sh  >> /var/log/update_script.log  
> @reboot	root	/home/flklein/update_script.sh  >> /var/log/update_script.log  

## 7. Script surveillance

```bash
$ cp /etc/crontab /home/flklein/tmp
```

```bash
$ vim /home/flklein/email.txt
```

```bash
$ vim /home/USER/watch_script.sh
```

Éditer :

> #!/bin/bash  
> cat /etc/crontab > /home/flklein/new  
> DIFF=$(diff new tmp)  
> if [ "$DIFF" != "" ]; then  
> 	sudo sendmail root@debian < /home/flklein/email.txt  
> 	rm -rf /home/flklein/tmp  
> 	cp /home/flklein/new /home/flklein/tmp  
> fi  

```bash
$ chmod +x watch_script.sh
```

### Ajout à crontab

```bash
$ sudo vim /etc/crontab
```

Éditer :

> 0  0	* * *	root	/home/flklein/watch_script.sh

## 8. Web

### Clé SSL

```bash
$ sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/debian.com.key -out /etc/ssl/certs/debian.com.crt
```

```bash
$ sudo vim /etc/apache2/sites-available/default-ssl.conf
```

Éditer :
```web
<IfModule mod_ssl.c>  
	<VirtualHost _default_:443>  
                ServerAdmin webmaster@localhost  
                DocumentRoot /var/www/html  

                ErrorLog ${APACHE_LOG_DIR}/error.log  
                CustomLog ${APACHE_LOG_DIR}/access.log combined  

                #Include conf-available/serve-cgi-bin.conf  

                #SSL Engine Switch:  
                #Enable/Disable SSL for this virtual host.  
                SSLEngine on  
                SSLCertificateFile      /etc/ssl/certs/debian.com.crt  
                SSLCertificateKeyFile /etc/ssl/private/debian.com.key  
                #SSLCertificateFile      /etc/ssl/certs/ssl-cert-snakeoil.pem  
                #SSLCertificateKeyFile /etc/ssl/private/ssl-cert-snakeoil.key  

......................  
......................  

      </VirtualHost>  
</IfModule> 
```

```bash
$ sudo apachectl configtest
$ sudo a2enmod ssl
$ sudo a2ensite default-ssl
```

```bash
$ sudo systemctl restart apache2.service
```

### Configuration

```bash
$ sudo cp /etc/apache2/sites-available/000-default.conf /etc/apache2/sites-available/001-default.conf
```

```bash
$ sudo vim /etc/apache2/sites-available/001-default.conf
```

Éditer :

> ServerName debian  
> DocumentRoot /var/www/html  

```bash
$ a2dissite 000-default.conf
$ a2ensite 001-default.conf
$ systemctl reload apache2
```

### Site

```bash
$ vi /var/www/html/site.html
```

Règle de port forwarding dans VirtualBox : `https	TCP		3443		443`

Depuis navigateur : `https://127.0.0.1:3443/site.html`
