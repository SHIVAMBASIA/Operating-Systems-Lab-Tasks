#abc kpl
# !/bin/sh
if [ -f $* ]
then
        echo "File Exists"
        grep -F $#
else
        echo "File not exists"
fi
 
