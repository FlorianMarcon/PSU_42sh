#! /bin/bash



if [ $# -ne 1 ]
then
    echo "USAGE: ./script.sh [list_test]"
    exit 1
fi

echo -e "\033[34mCOMPILATION\033[0m"

rm -rf mysh
make re -s -C ../../

if [ $? -ne 0 ]
then
    echo "Problem compilation"
    exit 1
fi

prog=42sh
cp ../../$prog ./



mkdir -p report
echo "NEW REPORT" > report/log




cat $1 | while read line ;
do
	echo $line | ./$prog > me.log
	ret_me=$?
	echo $line | tcsh > tcsh.log
	ret_tcsh=$?

	diff -q  me.log tcsh.log
	ret=$?

	if [ $ret -eq 0 ]
	then
		echo -e "\033[32msucceed about: " $line "\033[0m"
		echo "succeed about: " $line >> report/log
	else
		echo -e "\033[31mfailed about: " $line "\033[0m"
		echo "failed about:" $line >> report/log
	fi
	if [ $ret_me -ne $ret_tcsh ]
	then
		echo -e "\033[31mInvalid Exit status: me = $ret_me tcsh =  $ret_tcsh \033[0m"
	fi


done

exit 0





# other prog

cat $1 | while read line ;
do
    a=$(echo $line | tcsh)
    b=$(echo $line | ./$prog)

    diff -q <(echo $a) <(echo $b)
    ret=$?

    if [ $? -eq 0 ]
    then
	echo -e "\033[32msucceed about: " $line "\033[0m"
	echo "succeed about: " $line > report/log
    else
	echo -e "\033[33mfailed about: " $line "\033[0m"
	echo "failed about:" $line > report/log
    fi
done
