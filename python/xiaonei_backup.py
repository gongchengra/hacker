# -*- coding: utf-8 -*-


import sys
import os
import string
import htmllib
import urllib
import urlparse
import formatter
from sys import argv
from urllib import urlretrieve
from urllib import urlencode
import urllib2
import cookielib
import re

def write_content(f,content):
    f.write('\n\n'+content+'\n\n')
def addtorss(f,name):
    
    file=open(name)
    line = file.readlines()
    
# find the title of the blog entry
    f_title = ''
    data = '<title>'
    j = 0
    for eachLine in line:
        j=j+1
        m = re.search(data,eachLine)
        if m is not None:
            break
    strs = line[j-1]
    n_start = strs.find('<title>')+7
    n_end = strs.rfind('</title>')
    f_title = strs[n_start:n_end]
    
    f.write('\n\n\ntitle:'+ f_title + '\n')
# find the time of the blog entry
    f_time = ''
    data = '"timestamp"'
    j = 0
    for eachLine in line:
        j=j+1
        m = re.search(data,eachLine)
        if m is not None:
            break
    strs = line[j-1]
    n_start = strs.find('span class="timestamp"')+23
    n_end = strs.rfind('<span class="group">')
    f_time = strs[n_start:n_end]
    f.write('\ntime:'+ f_time + '\n')
    i = 0
    for eachLine in line:
        i = i + 1
        m = re.search('id="blogContent"',eachLine)
        if m is not None:
            break
    f_content = line[i+1]
    write_content(f,f_content)
    
    
def main():
# login to xiaonei
    cj = cookielib.LWPCookieJar()
    opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
    urllib2.install_opener(opener)
    opener.addheaders = [
            ("User-agent", "Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.5) Gecko/20031107 Debian/1.5-3"),
            ("Accept", "text/html, image/jpeg, image/png, text/*, image/*, */*")]
 
 # check args
    if len(sys.argv) <= 2:
        print "Usage: %s USERNAME PASSWORD" % (sys.argv[0])
        sys.exit(1)
    else:
        UserName = sys.argv[1]
        Password = sys.argv[2]
    data = {
            'email': UserName,
            'password': Password,
            'submit': '登录'
            }
    urldata = urlencode(data)
    r = opener.open("http://login.xiaonei.com/Login.do", urldata)
    results = r.read()
    open('start.html', 'w').write(results)
    r = urllib2.urlopen("http://blog.xiaonei.com/MyBlog.do")
    results = r.read()
    open('user.txt', 'w').write(results)
    
# get the whole article number
    file = open('user.txt')
    line = file.readlines()
    file.close()
    data = '当前显示1-10篇/共\d*篇'
    article_num = 0
    for eachLine in line:
        m = re.search(data,eachLine)
        if m is not None: 
            strs = m.group()
            num_start = strs.rfind('共')+3
            num_end = strs.rfind('篇')
            article_num = string.atoi(strs[num_start:num_end],10)
            break
            
            
#download the articles

    #make save xml file
    save_file = open('blog.txt','w')
    #save_file.write('\n\n<!--  generator="fled su bolan"  -->\n<rss version="2.0">\n<channel>')
    
    k = 1
    #get the first entry
    file = open('user.txt')
    line = file.readlines()
    file.close()
    data = 'http://blog.xiaonei.com/GetEntry.do\?id=\d*&owner=\d*'
    for eachLine in line:
        #print eachLine
        m = re.search(data,eachLine)
        if m is not None:
            strs = m.group()
            break
    r = urllib2.urlopen(strs)
    results = r.read()
    open('temp.txt', 'w').write(results)
    print "\nnow downloading the ", k, "th articles\n"
    addtorss(save_file,'temp.txt')
    
    for k in range(2,article_num):
        file = open('temp.txt')
        line = file.readlines()
        file.close()
        data = 'http://blog.xiaonei.com/GetPreBlog.do\?id=\d*&owner=\d*&time=\d*&op=pre'
        for eachLine in line:
            m = re.search(data,eachLine)
            if m is not None:
                strs = m.group()
                break
        r = urllib2.urlopen(strs)
        results = r.read()
        open('temp.txt','w').write(results)
        print "\nnow downloading the ", k, "th articles\n"
        addtorss(save_file,'temp.txt')
    save_file.close()
    
    os.remove('temp.txt')
    os.remove('start.html')
    os.remove('user.txt')   
    

if __name__ == '__main__':
    main()
