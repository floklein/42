while ($(kill -9 $(userdel $1 2>&1 | awk '{print $9}') 1>/dev/null))
do echo "Process killed.";
done
echo "Done!";
