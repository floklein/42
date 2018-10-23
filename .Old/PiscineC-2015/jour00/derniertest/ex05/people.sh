ldapsearch -LLL "uid=z*" cn | grep -ie cn | cut -c 5- | sort -rf;
