# -*- coding: utf-8 -*-
#ftp to hotel testing server
import os
from ftplib import FTP

ftp=FTP()
ftp.set_debuglevel(2)
ftp.connect('202.157.143.102', '14145')
ftp.login('Hoteltest', 'hoteltest999')
print   ftp.getwelcome()
bufsize = 1024

os.chdir(r"D:\Hotel\20120111\HotelMgt\HotelMgt")

#upload aspx and cs files
for file in os.listdir('.'):
    if (file.split('.')[-1] == 'aspx') or (file.split('.')[-1] == 'cs'):
        filename=file
        file_handler = open(filename, 'rb')
        ftp.storbinary( 'STOR '+ file,file_handler,bufsize)
        file_handler.close()

#upload bin\HotelMgt.dll
ftp.cwd(r'\bin')
filename= r'\bin\HotelMgt.dll'                                               
file_handler   =   open(filename, 'rb')                             
ftp.storbinary( 'STOR HotelMgt.dll',file_handler,bufsize)   #上传文件
file_handler.close()                    #关闭文件

#upload bin\HotelMgt.XmlSerializers.dll
ftp.cwd(r'\bin')
filename= r'\bin\HotelMgt.XmlSerializers.dll'                                               
file_handler   =   open(filename, 'rb')                             
ftp.storbinary( 'STOR HotelMgt.XmlSerializers.dll',file_handler,bufsize)   #上传文件
file_handler.close()                   #关闭文件

#upload obj\Release\HotelMgt.dll
ftp.cwd(r'\obj\Release')
filename= r'\obj\Release\HotelMgt.dll'                                               
file_handler   =   open(filename, 'rb')                          
ftp.storbinary( 'STOR HotelMgt.dll',file_handler,bufsize)   #上传文件
file_handler.close()                    #关闭文件

#upload bin\HotelMgt.dll
ftp.cwd(r'\obj\Release')
filename= r'\obj\Release\HotelMgt.XmlSerializers.dll'                                               
file_handler   =   open(filename, 'rb')                            
ftp.storbinary( 'STOR HotelMgt.XmlSerializers.dll',file_handler,bufsize)   #上传文件
file_handler.close()                   #关闭文件

ftp.set_debuglevel(0)
ftp.quit()

