#!/usr/bin/env python
#-*- coding:utf-8 -*-
__author__ = "Naich An (An@Naich.org)"
__copyright__ = "Copyright (c) 2011 Naich An" 

import sqlite3
import os
import sys
import datetime
reload(sys)
sys.setdefaultencoding('utf8') 

database = sqlite3.connect('./MicroMsg.db')

cur = database.cursor()

cur.execute('SELECT * FROM message')

a = cur.fetchall()
os.system('rm weixin.html')
f = open('weixin.html','a+')

f.write('<link rel="stylesheet" type="text/css" href="./style.css" />')
f.write('<div>')

messageType = ''
typeDict = {1:u'文字',3:u'图片',34:u'语音',43:u'视频',47:'动画表情'}
sendDict = {0:'float:left;background-color:#00CC99',1:'float:right;background-color:#CCCC66'}
for m in a:
	if m[7] == u'妹子的名字':
		sendTime = datetime.datetime.fromtimestamp(m[6]/1000.0).strftime('%Y-%m-%d %H:%M:%S')
		messageType = typeDict[m[2]]
		content = m[8]
		isSend = sendDict[m[4]]
		if messageType == u'视频':
			content = "<a href='./video/%s'>点击下载%s</a>"%(m[9],messageType)
		if messageType == u'语音':
			content = "<a href='./voice/%s'>点击下载%s</a>"%(m[9],messageType)
		if messageType == u'图片':
			cur.execute('SELECT bigImgPath FROM ImgInfo2 WHERE id = %d'%(int(m[9][12:])))
			try:
				imgPath = cur.fetchone()[0]
			except:
				imgPath = 'broken!'
			content = "<a href='./image/%s'>点击查看图片</a>"%(imgPath)
		contentLine = "<div class='content' width=500px><div class='talk' style='%s'><pre>%s</pre><div class='time'>%s</div></div></div>"
		f.write(contentLine%(isSend,content,sendTime))

f.write('</div>')