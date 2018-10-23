ifconfig | grep 'inet ' | cut -d ' ' -f2
IP_VAR=$(ifconfig | grep 'inet ' | cut -d ' ' -f2 | wc -l | cut -c 8-)
if [ -z $IP_VAR ]
then
	echo "I am lost!\n"
fi
