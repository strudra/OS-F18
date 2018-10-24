cd tmp/
alpha=1;

for i in $(ls); 
do
	if [ $(stat --printf="%h\n" $i) -gt $alpha ]
	then
		beta=$(pwd)
		set -- $(ls -i $i);
		echo $2
		cd ~/
		find -inum $1
		cd $beta
	fi
done;
