

#!/bin/sh

hr=`date +%r | awk -F: '{print $1}'`
hr=`expr $hr + 0`

min=`date +%r | awk -F: '{print $2}'`
min=`expr $min + 0`

sec=`date +%r | awk -F: '{print $3}' | awk '{print $1}'`

meridian=`date +%r | awk -F: '{print $3}' | awk '{print $2}'`
num1=(zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty twenty-one twenty-two twenty-three twenty-four twenty-five twenty-six twenty-seven twenty-eight twenty-nine thirty thirty-one thirty-two thirty-three thirty-four thirty-five thirty-six thirty-seven thirty-eight thirty-nine forty forty-one forty-two forty-three forty-four forty-five forty-six forty-seven forty-eight forty-nine fifty fifty-one fifty-two fifty-three fifty-four fifty-five fifty-six fifty-seven fifty-eight fifty-nine) #  for hour

echo "the time is: ${num1[hr]} hour ${num1[min]} minutes ${num1[sec]} seconds $meridian"

month=`date +%B`
date=`date +%d`

echo "the date is : ${num1[date]} $month"