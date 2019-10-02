# abc kpl
# !/bin/sh
s=0
while [ $# -ne 0 ]
do
	a=2
	while [ $a -ne $1 ]
	do
		m=`expr $1 \% $a`
		if [ $m -eq 0 ]
		then
			flag=0
			break
		else
			flag=1
		fi
		a=`expr $a + 1`
	done
	if [ $flag -eq 1 ]
	then
		s=`expr $s + $1`
	fi
	shift
done
echo $s

