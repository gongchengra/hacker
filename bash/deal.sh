#!/bin/bash
for f in *.xml
do php /home/gongcheng/code/cocoon/ui2348/validate.php $f 2> $f.txt
done
rm error.txt
for f in *.txt
do
    echo $f >> error.txt
    cat $f >> error.txt
done
sed -i '/no DTD/d' error.txt
sed -i '/external subset/d' error.txt
sed -i '/I\/O/d' error.txt

