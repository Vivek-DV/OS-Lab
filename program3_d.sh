#1/bin/bash
if [ "$#" -ne 2 ];then
	echo "Usage:$0<num1><num2>"
	exit 1
fi
num1="$1"
num2="$2"
sum=$((num1+num2))
difference=$((num1-num2))
product=$((num1*num2))
echo "Sum: $sum"
echo "Difference: $difference"
echo "Product: $product"
if [ "$2" -eq 0 ];then
	echo "Cannot divide by 0"
	exit 1
fi
div=$(bc <<< "scale = 2;$num1/$num2")
echo "Quotient: $div"
