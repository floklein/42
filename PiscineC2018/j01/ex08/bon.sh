ldapsearch -Q -LLL "(cn=*BON*)" cn | grep cn | wc -l | cut -c 6-
