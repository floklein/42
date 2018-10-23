ifconfig | grep 'inet ' | grep -v '127.0.0.1' | cut -d ' ' -f2
IP_VAR=$(ifconfig | grep 'inet ' | grep -v '127.0.0.1' | cut -d ' ' -f2 | wc -l | cut -c 8-)
if [ -z $IP_VAR ]
then
	echo "I am lost!\n"
fi
