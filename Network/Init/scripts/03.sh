let "tab = $1"
list=$(cat libft/*.c | grep '^\w.*$' | grep -v '^static' | sed 's/	\{1,\}/'$(printf "%${tab}s")'/g')
echo -e "$list"
lines=$(echo -e "$list" | wc -l)
echo "$lines"
let "l = $lines"
echo "$l"
