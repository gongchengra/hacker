#!/bin/bash
bzip2 -d blog.bak.sql.bz2
mysql -h localhost -u root -p wordpress < blog.bak.sql
