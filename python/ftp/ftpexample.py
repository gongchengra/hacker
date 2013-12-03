# -*- coding: utf-8 -*-
'''
http://topic.csdn.net/t/20050121/17/3744436.html
转自www.ringkee.com的一篇文章

ftplib模块定义了FTP类和一些方法，用以进行客户端的ftp编程。我们可用python编写一个自已的ftp客户端程序，用于下载文件或镜像站点。如果想了解ftp协议的详细内容，请参考RFC959。

该模块是python的通用模块，所以默认应该已安装。ftplib模块使用很简单，暂时只有一个FTP类和十几个函数。下面用一个交互方式演示一下ftplib的主要功能。

> > >   from   ftplib   import   FTP
> > >   ftp=FTP( 'ftp.python.org ')
> > >   ftp.login()
'230   Login   successful. '
> > >   ftp.dir()
drwxrwxr-x         7   1004           1004                     512   Aug   13   01:35   pub
> > >   ftp.cwd( 'pub ')
'250   Directory   successfully   changed. '
> > >   ftp.dir()
drwxrwxr-x         5   1000           1004                   1024   Dec   24   11:04   docs.python.org
drwxrwsr-x         2   1002           1004                     512   Oct   12     2001   jython
lrwx------         1   0                 1003                       25   Aug   03     2001   python   ->   www.python.org/ftp/python
drwxr-xr-x         9   1018           1004                     512   Feb   02   03:44   pyvault
drwxr-xr-x         2   1005           1004                     512   May   06     2003   tmp
drwxrwsr-x       59   1004           1004                   3072   Feb   03   14:58   www.python.org
> > >   ftp.quit()
'221   Goodbye. '

下面一个下载文件的示例

#!/usr/bin/env   python

#author:Jims   of   www.ringkee.com
#create   date:   2005/02/05
#description:   Using   ftplib   module   download   a   file   from   a   ftp   server.

from   ftplib   import   FTP

ftp=FTP()

ftp.set_debuglevel(2)                             #打开调试级别2，显示详细信息
ftp.connect( 'ftp_server ', 'port ')       #连接
ftp.login( 'username ', 'password ')       #登录，如果匿名登录则用空串代替即可

print   ftp.getwelcome()                           #显示ftp服务器欢迎信息
ftp.cwd( 'xxx/xxx/ ')                                 #选择操作目录
bufsize   =   1024                                           #设置缓冲块大小
filename= 'dog.jpg '                                                
file_handler   =   open(filename, 'wb ').write                             #以写模式在本地打开文件
ftp.retrbinary( 'RETR   dog.jpg ',file_handler,bufsize)       #接收服务器上文件并写入本地文件
ftp.set_debuglevel(0)                                                                   #关闭调试

ftp.quit()                                                                                         #退出ftp服务器

下面一个上传文件的示例，要成功运行该脚本，需在ftp服务器上有上传文件的权限。

#!/usr/bin/env   python

#author:Jims   of   www.ringkee.com
#create   date:   2005/02/05
#description:   Using   ftplib   module   upload   a   file   to   a   ftp   server.

from   ftplib   import   FTP

ftp=FTP()

ftp.set_debuglevel(2)
ftp.connect( 'ftp_server ', 'port ')
ftp.login( 'username ', 'password ')

print   ftp.getwelcome()
ftp.cwd( 'xxx/xxx/ ')
bufsize   =   1024
filename= 'dog.jpg '
file_handler   =   open(filename, 'rb ')
ftp.storbinary( 'STOR   dog.jpg ',file_handler,bufsize)       #上传文件
ftp.set_debuglevel(0)

file_handler.close()                   #关闭文件
ftp.quit()

'''

from ftplib import FTP

ftp=FTP()

ftp.set_debuglevel(2)
ftp.connect('202.157.143.102', '14145')
ftp.login('Hotelwstest', 'hotelwstest999')

print   ftp.getwelcome()
bufsize = 1024

'''
#download HotelService.asmx.cs
filename= r'D:\Hotel\20120111\wsHotel\wsHotel\HotelService.asmx.cs'                                               
file_handler   =   open(filename, 'wb ').write                             #以写模式在本地打开文件
ftp.retrbinary( 'RETR HotelService.asmx.cs',file_handler,bufsize)       #接收服务器上文件并写入本地文件

#download Models\HotelTask.cs
ftp.cwd(r'\Models\HotelTask.cs')
filename= r'D:\Hotel\20120111\wsHotel\wsHotel\Models\HotelTask.cs'                                               
file_handler   =   open(filename, 'wb ').write   #以写模式在本地打开文件
ftp.retrbinary( 'RETR HotelTask.cs',file_handler,bufsize)       #接收服务器上文件并写入本地文件

#download bin\wsHotel.dll
ftp.cwd(r'\bin')
filename = r'D:\Hotel\20120111\wsHotel\wsHotel\bin\wsHotel.dll'                                             
file_handler   =   open(filename, 'wb ').write   #以写模式在本地打开文件
ftp.retrbinary( 'RETR wsHotel.dll',file_handler,bufsize)       #接收服务器上文件并写入本地文件

#download obj\Release\wsHotel.dll
ftp.cwd(r'\obj\Release')
filename = r'D:\Hotel\20120111\wsHotel\wsHotel\obj\Release\wsHotel.dll'                                              
file_handler   =   open(filename, 'wb ').write   #以写模式在本地打开文件
ftp.retrbinary( 'RETR wsHotel.dll',file_handler,bufsize)       #接收服务器上文件并写入本地文件

'''

#upload HotelService.asmx.cs
filename= r'D:\Hotel\20120111\wsHotel\wsHotel\HotelService.asmx.cs'                                               
file_handler   =   open(filename, 'rb')                            
ftp.storbinary( 'STOR HotelService.asmx.cs',file_handler,bufsize)   #上传文件
file_handler.close()                    #关闭文件

#upload Models\HotelTask.cs
ftp.cwd(r'\Models\HotelTask.cs')
filename= r'D:\Hotel\20120111\wsHotel\wsHotel\Models\HotelTask.cs'                                               
file_handler   =   open(filename, 'rb ')   
ftp.storbinary( 'STOR HotelTask.cs',file_handler,bufsize)           #上传文件
file_handler.close()                    #关闭文件

#upload bin\wsHotel.dll
ftp.cwd(r'\bin')
filename = r'D:\Hotel\20120111\wsHotel\wsHotel\bin\wsHotel.dll'
file_handler = open(filename, 'rb ')
ftp.storbinary('STOR wsHotel.dll',file_handler,bufsize)             #上传文件
file_handler.close()                    #关闭文件

#upload obj\Release\wsHotel.dll
ftp.cwd(r'\obj\Release')
filename = r'D:\Hotel\20120111\wsHotel\wsHotel\obj\Release\wsHotel.dll'
file_handler = open(filename, 'rb')
ftp.storbinary('STOR wsHotel.dll',file_handler,bufsize)             #上传文件
file_handler.close()                    #关闭文件

ftp.set_debuglevel(0)
ftp.quit()



