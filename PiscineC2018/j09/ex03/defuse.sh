touch -A -000001 -a bomb.txt
stat -t %s bomb.txt | awk -F ' ' '{print $9}' | tr -d '"'
