#!/usr/bin/env python 
# -*- coding: gbk -*-
# http://zhouzaibao.iteye.com/blog/561390
'''
python 开发的通过FTP上传下载文件类

    博客分类：
    python相关

PythonOSF#

原创文章，转载请注明出处:http://zhouzaibao.iteye.com

   前段时间使用java写了一个支持断点续传的FTP类库，但是这个库在使用过程中还是有点问题，最近在学习python，就打算用python写一个。

    其实在使用java写的那个过程中也遇到了一些比较难解决的问题，比如说在多个ftp客户端同事向一个FTP服务器端发送上传命令，这个时候会造成线程挂起不会抛异常也不会退出，这个让我头疼的好久，现在用python写了一个，

    目前更改的类主要实现的断点下载和断点上传，欢迎大家批评指正。
'''
from ftplib import FTP
import sys
import os.path

class MyFTP(FTP):
    '''
    conncet to FTP Server
    '''
    def ConnectFTP(self,remoteip,remoteport,loginname,loginpassword):
        ftp=MyFTP()
        try:
            ftp.connect(remoteip,remoteport)
        except:
            return (0,'conncet failed')
        else:
            try:
                ftp.login(loginname,loginpassword)
            except:
                return (0,'login failed')
            else:
                return (1,ftp)
    
    def download(self,remoteHost,remotePort,loginname,loginpassword,remotePath,localPath):
        #connect to the FTP Server and check the return
        res = self.ConnectFTP(remoteHost,remotePort,loginname,loginpassword)
        if(res[0]!=1):
            print res[1]
            sys.exit()
        
        #change the remote directory and get the remote file size
        ftp=res[1]
        ftp.set_pasv(0)
        dires = self.splitpath(remotePath)
        if dires[0]:
            ftp.cwd(dires[0])
        remotefile=dires[1]
        print dires[0]+' '+ dires[1]
        fsize=ftp.size(remotefile)
        if fsize==0 :
            return
        
        #check local file isn't exists and get the local file size
        lsize=0L
        if os.path.exists(localPath):
            lsize=os.stat(localPath).st_size
            
        if lsize >= fsize:
            print 'local file is bigger or equal remote file'
            return
        blocksize=1024
        cmpsize=lsize
        ftp.voidcmd('TYPE I')
        conn = ftp.transfercmd('RETR '+remotefile,lsize)
        lwrite=open(localPath,'ab')
        while True:
            data=conn.recv(blocksize)
            if not data:
                break
            lwrite.write(data)
            cmpsize+=len(data)
            print '\b'*30,'download process:%.2f%%'%(float(cmpsize)/fsize*100),
        lwrite.close()
        ftp.voidcmd('NOOP')
        ftp.voidresp()
        conn.close()
        ftp.quit()
    
    def upload(self,remotehost,remoteport,loginname,loginpassword,remotepath,localpath,callback=None):
        if not os.path.exists(localpath):
            print "Local file doesn't exists"
            return
        self.set_debuglevel(2)
        res=self.ConnectFTP(remotehost,remoteport,loginname,loginpassword)
        if res[0]!=1:
            print res[1]
            sys.exit()
        ftp=res[1]
        remote=self.splitpath(remotepath)
        ftp.cwd(remote[0])
        rsize=0L
        try:
            rsize=ftp.size(remote[1])
        except:
            pass
        if (rsize==None):
            rsize=0L
        lsize=os.stat(localpath).st_size
        if (rsize==lsize):
            print 'remote filesize is equal with local'
            return
        if (rsize<lsize):
            localf=open(localpath,'rb')
            localf.seek(rsize)
            ftp.voidcmd('TYPE I')
            datasock,esize=ftp.ntransfercmd("STOR "+remote[1],rsize)
            cmpsize=rsize
            while True:
                buf=localf.read(1024)
                if not len(buf):
                    print '\rno data break'
                    break
                datasock.sendall(buf)
                if callback:
                    callback(buf)
                cmpsize+=len(buf)
                print '\b'*30,'uploading %.2f%%'%(float(cmpsize)/lsize*100),
                if cmpsize==lsize:
                    print '\rfile size equal break'
                    break
            datasock.close()
            print 'close data handle'
            localf.close()
            print 'close local file handle'
            ftp.voidcmd('NOOP')
            print 'keep alive cmd success'
            ftp.voidresp()
            print 'No loop cmd'
            ftp.quit()
            
        
    def splitpath(self,remotepath):
        position=remotepath.rfind('/')
        return (remotepath[:position+1],remotepath[position+1:])
      
        
if __name__=='__main__':
    lf = MyFTP()
    lf.download('202.157.143.102',14145,'Hotelwstest','hotelwstest999','HotelService.asmx.cs',r'D:\cublog\cmd.reg')
