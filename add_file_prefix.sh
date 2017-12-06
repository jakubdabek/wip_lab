#!/bin/bash
files=$(find -name '*.[ch]' | xargs grep -L 'Jakub')
for filename in $files
do
	sed -i "1s;^;//$(basename $filename)\n//Jakub Dąbek\n;" $filename
done
