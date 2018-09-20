cat $1 | grep -i 'nicolas\tbauer' | awk '{print $(NF-1)}' | grep -v '\.'
