# http://www.java2s.com/Tutorial/Python/0420__Network/Binaryfileupload.htm

from ftplib import FTP

ftp = FTP()
timeout = 30
port = 14145
ftp.connect('202.157.143.102',port,timeout)
ftp.login('Hotelwstest','hotelwstest999')
print "File List:"
files = ftp.dir()
print files

'''
gFile = open("HotelService.asmx.cs", "wb")
ftp.retrbinary('RETR HotelService.asmx.cs', gFile.write)
gFile.close()
ftp.quit()
'''

'''
fp = open('testftp.txt','rb')
ftp.storbinary('STOR testftp.txt', fp)
fp.close()
ftp.quit()
'''

fp = open('D:\gc\Dropbox\share\cmd.reg','rb')
ftp.cwd('/bin')
ftp.storbinary('STOR cmd.reg', fp)
fp.close()
ftp.quit()

'''
gFile = open("HotelService.asmx.cs", "r")
buff = gFile.read()
print buff
gFile.close()
'''
