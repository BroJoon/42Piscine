ifconfig -a link | grep ether | tr -d '\t ' | sed 's/ether//g'
