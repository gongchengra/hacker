#!/bin/bash
sudo apt-get install python-gevent python-pip
sudo pip install shadowsocks
sudo add-apt-repository ppa:hzwhuang/ss-qt5
sudo apt-get update
cat > ~/.config/shadowsocks/gui-config.json <<EOF
{
    "autoHide": true,
    "autoStart": false,
    "configs": [
    {
        "backend": "",
        "custom_arg": "",
        "fast_open": false,
        "local_address": "127.0.0.1",
        "local_port": "1080",
        "method": "aes-256-cfb",
        "password": "aspsho2009",
        "profile": "alan",
        "server": "168.143.179.150",
        "server_port": "8388",
        "timeout": "600",
        "type": "libQtShadowsocks"
    }
    ],
    "debug": false,
    "index": 0,
    "relative_path": false,
    "translucent": true,
    "useSystray": false
}
EOF
