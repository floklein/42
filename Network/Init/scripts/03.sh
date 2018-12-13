let "tab = $1"
list=$(cat libft/*.c | grep '^\w.*$' | grep -v '^static' | sed 's/	\{1,\}/			/g')
echo -e "$list"
