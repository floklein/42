var=$(stat -t %s bomb.txt | awk -F ' ' '{print $12}' | tr -d '"')
var2=$(echo $((var-1)))
touch -r bomb.txt -a $var2
stat -t %s bomb.txt | awk -F ' ' '{print $12}' | tr -d '"'
