ldapsearch -Q -LLL 'uid=z*' cn | grep "cn" | cut -c 5- | sort -rf
