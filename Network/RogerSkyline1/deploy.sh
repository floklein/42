# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <flklein@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 19:04:43 by flklein           #+#    #+#              #
#    Updated: 2019/01/04 23:34:05 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Port forwarding in VirtualBox:
# ssh		3022		22
# https		3443		443

VBoxManage clonevm VM\ roger-skyline --name VM\ rs-deploy &> /dev/null &
ID=$(ps | grep -m1 clonevm | awk '{print $1}')
RED='\033[1;31m'
GRE='\033[1;32m'
LCY='\033[1;36m'
YEL='\033[1;33m'
NC='\033[0m'
let "i = 0"
let "n = 1"
let "s = 0"
echo "Deployment started on process ${RED}$ID${NC}."
while [ "$(ps -p $ID | grep $ID)" != "" ]
do
	if [ $n -eq 1 ]
	then
		printf "${YEL}["
	elif [ $n -eq 10000 ]
	then
		printf "${YEL}] "
		let "n = 0"
		if [ $s -eq 0 ]
		then
			printf "${GRE}✓ Network\n"
		fi
		if [ $s -eq 1 ]
		then
			printf "${GRE}✓ SSH\n"
		fi
		if [ $s -eq 2 ]
		then
			printf "${GRE}✓ Scripts\n"
		fi
		if [ $s -eq 3 ]
		then
			printf "${GRE}✓ Web\n"
		fi
		if [ $s -eq 4 ]
		then
			printf "${GRE}✓ VM\n"
		fi
		let "s = s + 1"
		let "i = 0"
	elif [ $i -eq 1000 ]
	then
		printf "${YEL}❚"
		let "i = 0"
	fi
	let "i = i + 1"
	let "n = n + 1"
done
while [ $n -lt 10000 ]
do
	if [ $(($n % 1000)) -eq 0 ]
	then
		printf "${YEL}❚"
	fi
	let "n = n + 1"
done
echo "${YEL}] ${LCY}Done."
