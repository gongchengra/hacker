#!/bin/bash
#sudo ufw default deny
sudo ufw allow ssh
sudo ufw allow http
sudo ufw allow https
sudo ufw allow git
sudo ufw allow mysql
sudo ufw allow rsync
sudo ufw allow 5501
sudo ufw enable
