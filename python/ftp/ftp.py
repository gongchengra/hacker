# -*- coding: cp936 -*-
# 例：FTP编程
'''
http://www.17jo.com/program/python/net/FTP.html

Python：FTP上传和下载文件编程

作者：保⑩洁
Python 编程中使用ftplib模块的FTP对象，可以进行方便的实现FTP客户端功能，简易的流程如下：

# FTP操作基本流程示意

FTP.connect(服务器地址,端口,超时时间)	# 连接服务器
FTP.login(用户名,用户密码) 		# 用户登录
FTP.cwd(路径)    			# 设置要操作FTP文件夹路径
FTP.nlst()			# 获得目录下文件
FTP.retrbinary(文件名,回调函数) 	# 下载FTP上的文件
FTP.delete(文件名)            	# 删除FTP文件
ftp.storbinary(文件名, 文件对象) 	# 上传FTP文件
ftp.quit()                  	# 退出FTP服务器
connect(服务器地址,端口[,超时]) ：连接FTP服务器地址。

login(用户名，用户密码) ：进行FTP登陆，然后才能对文件进行操作。

cwd(路径) ：设置ftp的当前操作的路径

nlst() ：获得当前路径下的所有文件及文件夹名。

retrbinary(FTP上文件名,处理回调函数名) ：将ftp上的文件保存到本机上。

delete(文件名) ：用于删除文件。

storbinary(文件名称, 文件对象) ：用于上传文件。

quit() ：退出ftp服务器并断开连接。

具体的用法如以下例子：

from ftplib import FTP
    
ftp = FTP()
timeout = 30
port = 21
ftp.connect('192.168.1.188',port,timeout) # 连接FTP服务器
ftp.login('UserName','888888') # 登录
print ftp.getwelcome()  # 获得欢迎信息 
ftp.cwd('file/test')    # 设置FTP路径
list = ftp.nlst()       # 获得目录列表
for name in list:
    print(name)             # 打印文件名字
path = 'd:/data/' + name    # 文件保存路径
f = open(path,'wb')         # 打开要保存文件
filename = 'RETR ' + name   # 保存FTP文件
ftp.retrbinary(filename,f.write) # 保存FTP上的文件
ftp.delete(name)            # 删除FTP文件
ftp.storbinary('STOR '+filename, open(path, 'rb')) # 上传FTP文件
ftp.quit()                  # 退出FTP服务器
'''
from ftplib import FTP
ftp = FTP()
timeout = 30
port = 14145
ftp.connect('202.157.143.102',port,timeout)
ftp.login('Hotelwstest','hotelwstest999')
print ftp.getwelcome()
list = ftp.nlst()
for name in list:
    print (name)
f = open("testftp.txt", "wb")
ftp.storbinary('D:\gc\Dropbox\share\python\testftp.txt', f)


