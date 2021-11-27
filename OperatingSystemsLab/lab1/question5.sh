

#!/bin/sh

cmd=`sed 5q $1`
a=($cmd)
len=${#a[@]}

i=0
while [ $i -lt $len ]
do
    echo ${a[i]}
    i=`expr $i + 1`
done
