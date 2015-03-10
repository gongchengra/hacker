#!/bin/bash
mysqldump --add-drop-table -h localhost -u root -p wordpress | bzip2 -c > blog.bak.sql.bz2
