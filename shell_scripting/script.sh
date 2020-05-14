
echo "$$"
if [ $# -ne 2 ]
then
	echo "invalid no of data"
	exit 1
fi
a=0
while [ $1 ]
do
a=`expr $a + $1`
shift
done

echo "result=$a"

