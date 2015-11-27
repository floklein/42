cat $1 | grep -i 'nicolas\tbomber' | awk -F'\t' '{print $3}' | awk -F'[^0-9]*' '$1'
