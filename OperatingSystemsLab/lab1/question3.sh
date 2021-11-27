
#!bin/sh

cmd=`du -a | sort -n -r | head -n 3`

a=($cmd)

len=${#a[@]}

i=0
while [ $i -lt $len ]
do 
    value=`expr $i + 1`
    echo "filename : ${a[value]} , size : ${a[i]}"
    i=`expr $i + 2`
done

    




