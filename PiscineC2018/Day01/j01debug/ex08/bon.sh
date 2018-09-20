ldapsearch -Q -LLL "(sn=*BON*)" cn | grep cn | wc -l | cut -c 6-
