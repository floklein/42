ldapsearch -x -LLL uid='z*' | grep -i 'cn:' | sort -dr | cut -c5-
