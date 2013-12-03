# -*- coding: utf-8 -*-
from ftplib import FTP

ftp=FTP()

ftp.set_debuglevel(2)
ftp.connect('202.157.143.102', '14145')
ftp.login('Hotelwstest', 'hotelwstest999')

print   ftp.getwelcome()
bufsize = 1024

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


