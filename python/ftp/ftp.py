# -*- coding: cp936 -*-
# ����FTP���
'''
http://www.17jo.com/program/python/net/FTP.html

Python��FTP�ϴ��������ļ����

���ߣ������
Python �����ʹ��ftplibģ���FTP���󣬿��Խ��з����ʵ��FTP�ͻ��˹��ܣ����׵��������£�

# FTP������������ʾ��

FTP.connect(��������ַ,�˿�,��ʱʱ��)	# ���ӷ�����
FTP.login(�û���,�û�����) 		# �û���¼
FTP.cwd(·��)    			# ����Ҫ����FTP�ļ���·��
FTP.nlst()			# ���Ŀ¼���ļ�
FTP.retrbinary(�ļ���,�ص�����) 	# ����FTP�ϵ��ļ�
FTP.delete(�ļ���)            	# ɾ��FTP�ļ�
ftp.storbinary(�ļ���, �ļ�����) 	# �ϴ�FTP�ļ�
ftp.quit()                  	# �˳�FTP������
connect(��������ַ,�˿�[,��ʱ]) ������FTP��������ַ��

login(�û������û�����) ������FTP��½��Ȼ����ܶ��ļ����в�����

cwd(·��) ������ftp�ĵ�ǰ������·��

nlst() ����õ�ǰ·���µ������ļ����ļ�������

retrbinary(FTP���ļ���,����ص�������) ����ftp�ϵ��ļ����浽�����ϡ�

delete(�ļ���) ������ɾ���ļ���

storbinary(�ļ�����, �ļ�����) �������ϴ��ļ���

quit() ���˳�ftp���������Ͽ����ӡ�

������÷����������ӣ�

from ftplib import FTP
    
ftp = FTP()
timeout = 30
port = 21
ftp.connect('192.168.1.188',port,timeout) # ����FTP������
ftp.login('UserName','888888') # ��¼
print ftp.getwelcome()  # ��û�ӭ��Ϣ 
ftp.cwd('file/test')    # ����FTP·��
list = ftp.nlst()       # ���Ŀ¼�б�
for name in list:
    print(name)             # ��ӡ�ļ�����
path = 'd:/data/' + name    # �ļ�����·��
f = open(path,'wb')         # ��Ҫ�����ļ�
filename = 'RETR ' + name   # ����FTP�ļ�
ftp.retrbinary(filename,f.write) # ����FTP�ϵ��ļ�
ftp.delete(name)            # ɾ��FTP�ļ�
ftp.storbinary('STOR '+filename, open(path, 'rb')) # �ϴ�FTP�ļ�
ftp.quit()                  # �˳�FTP������
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


