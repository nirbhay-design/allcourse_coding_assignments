#!/bin/sh
#!/bin/bash

# cmd=`awk 'BEGIN {print rand()*100;}'`
cmd=`awk 'BEGIN {for(i=0;i<10;i++) print int(rand()*100)}'`

echo $cmd

