#!/bin/sh
#!bin/bash

i=2
while [ $i -gt -1 ]
do
    echo "NirbhaySharma~$: " 
    read commands
    if [ $commands = "exit" ]
    then 
        i=-2
    fi 
    
    echo `$commands`


done