RED='\033[1;31m'
GRE='\033[1;32m'
LCY='\033[1;36m'
NC='\033[0m'
if [ -z "$1" ] || [ -z "$2" ]
then
	echo "${RED}✗ ${NC}usage: ./proto-list <sources folder> <number of tabs> [mode { | display}]"
	exit 1
fi
let "n = $2"
let "i = 0"
tabs=""
while [ $i -lt $n ]
do
	tabs="$tabs	"
	let "i = i + 1"
done
list=$(cat $1/*.c | grep '^\w.*$' | grep -v '^static' | sed "s/	\{1,\}/$tabs/g"| sed 's/$/;/')
let "lines=$(echo "$list" | wc -l)"
if [ "$3" = "display" ]
then
	echo "$list"
fi
echo "${GRE}✓ Done! ${RED}$lines ${NC}prototypes were copied to your ${LCY}clipboard${NC}."
echo "$list" | pbcopy
