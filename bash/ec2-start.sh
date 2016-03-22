InstanceId=$(aws ec2 describe-instances --profile=alan|grep InstanceId|sed -e 's/^[^i]*//' -e 's/",//')
#echo $InstanceId
aws ec2 start-instances --instance-ids $InstanceId --profile=alan
sleep 1m
screen -X -S shadow quit
IP=$(aws ec2 describe-instances --profile=alan|grep PublicIp|grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b"|sort -u)
sed -i "/Host aws/,+1c\\Host aws\nHostName $IP" ~/.ssh/config
#ssh -i ~/.ssh/alanaws.pem -o 'IdentitiesOnly yes' -o 'StrictHostKeyChecking no' ubuntu@$IP 'screen -dmS shadow /home/ubuntu/shadowsocks/shadowsocks-server-linux64-1.1.4 -c=/home/ubuntu/shadowsocks/config.json'
ssh aws 'screen -dmS shadow /home/ubuntu/shadowsocks/shadowsocks-server-linux64-1.1.4 -c=/home/ubuntu/shadowsocks/config.json'
sed -r -i "s/\"([0-9]{1,3}\.){3}[0-9]{1,3}:/\"$IP:/" ~/software/shadowsocks/config.json
screen -dmS shadow /home/gongcheng/software/shadowsocks/shadowsocks-local-linux64-1.1.4 -c=/home/gongcheng/software/shadowsocks/config.json
