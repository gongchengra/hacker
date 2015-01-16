#!/bin/bash
sudo apt-get install python-gevent python-pip
sudo pip install shadowsocks
sudo cat > /etc/shadowsocks.json <<EOF
{
    "server":"0.0.0.0",
    "server_port":8388,
    "local_port":1080,
    "password":"aspsho2009",
    "timeout":600,
    "method":"aes-256-cfb"
}
EOF
sudo screen ssserver -c /etc/shadowsocks/config.json 
sudo cat >> /etc/rc.local <<EOF
/usr/local/bin/ssserver -c /etc/shadowsocks/config.json
EOF
