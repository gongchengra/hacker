InstanceId=$(aws ec2 describe-instances --profile=alan|grep InstanceId|sed -e 's/^[^i]*//' -e 's/",//')
aws ec2 stop-instances --instance-ids $InstanceId --profile=alan
screen -X -S shadow quit
