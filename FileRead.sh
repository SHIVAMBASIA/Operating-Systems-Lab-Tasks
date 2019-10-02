# abc kpl
# !/bin/sh
echo "abc"
read c d
if [ $c -eq 2 -a $d -eq 4 ]
then
	echo "hl"
fi
echo $#
echo $*
shift
echo $#
echo $*
echo $1

