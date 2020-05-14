echo "enter first number"
read a
echo "enter second number"
read b
echo "enter opration from below"
echo "-+/*"
read c
if [ $c = "+" ]
then
d=`expr $a + $b`
elif [ $c = "-" ]
then
d=`expr $a - $b`
elif [ $c = "/" ]
then
d=`expr $a / $b`
elif [ $c = "*" ]
then
d=`expr $a "*" $b`

fi

echo "result=$d"
