#abc kpl
# !/bin/sh
if [ -f $* ]
then
        echo "File Exists"
        ls -l $*
        chmod -x -w $*
        echo "Write and execute functions deleted"
        echo "New permissions are"
        ls -l $*
else
        echo "File not exists"
fi     
