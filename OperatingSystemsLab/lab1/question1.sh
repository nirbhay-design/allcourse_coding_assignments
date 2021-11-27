

#!/bin/sh

cmd1=`wc -l < $1`
cmd2=`wc -w < $1`

a=$cmd1
a=`expr $a + 1`

echo "number of lines are-"  $a
echo "number of words are-"  $cmd2

# 'Ubuntu Mono'
