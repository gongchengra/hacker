#!/bin/bash
# From http://wenzzz.com/index.php/blog/2015/10/php%E7%BC%96%E7%A0%81%E8%A7%84%E8%8C%83%E6%A3%80%E6%9F%A5%E5%B7%A5%E5%85%B7
DY3_SVN_ROOT=http://svn_url/xxxx_project_dir
CODE_PATH=/tmp/xxxx_project_dir

/bin/rm -rf $CODE_PATH

/bin/mkdir -p $CODE_PATH
/usr/bin/svn co --force $DY3_SVN_ROOT/ $CODE_PATH/

chmod 777 -R $CODE_PATH;

################
##
## 自动更新文件的编码格式，把doc转换为unix，去掉^M符号，修改的文件会自动提交svn
##
################

##遍历目录下的php文件
function searchFile()
{  
    for file in ` ls $1 `  
    do  
        if [ -d $1"/"$file ];then  
            searchFile $1"/"$file  
        else  
            if [ "${file##*.}" = "php" ];then
                dos2unix -o $1"/"$file

                sed -e 's/^M//g' $1"/"$file > $1"/"$file.bak
                mv $1"/"$file.bak $1"/"$file
            fi 
        fi 
    done
}

searchFile $CODE_PATH

## 提交svn
cd $CODE_PATH;
/usr/bin/svn ci -m 'doc2unix by auto script'

################


################
##
## 对svn代码进行编码规范检查，同时，执行自动修复，修复后代码自动提交svn
##
################

today=`/bin/date +%Y%m%d`;           

## 自动修复不符合规范的代码格式
/usr/local/php/bin/php /data/php_code_checker/PHP_CodeSniffer/scripts/phpcbf --encoding=utf8 --tab-width=4 \
--report=full \
--report-file=/tmp/phpcbfReportFixed$today \
--standard=PSR1,PSR2 --extensions=php --ignore='/simpletest/' \
--ignore='/phptest/' --ignore='/function/' --ignore='/config/' \
--ignore='MemcachedClient.class.php,Pop3.class.php,Smtp.class.php,index.php,HttpsqsClient.class.php,Core.function.php,AccessFilter.class.php,st.init.php,lp.init.php' \
$CODE_PATH

cd $CODE_PATH;
/usr/bin/svn ci -m 'fixed coding standards by phpcbf script'

## 检测不符合规范的代码，无法自动修复的代码。
/usr/local/php/bin/php /data/php_code_checker/PHP_CodeSniffer/scripts/phpcs --encoding=utf8 --tab-width=4 \
--report=full \
--report-file=/tmp/phpcsReport$today \
--standard=PSR1,PSR2 --extensions=php --ignore='/simpletest/' \
--ignore='/phptest/' --ignore='/function/' --ignore='/config/' \
--ignore='MemcachedClient.class.php,Pop3.class.php,Smtp.class.php,index.php,HttpsqsClient.class.php,Core.function.php,AccessFilter.class.php,st.init.php,lp.init.php' \
$CODE_PATH

if [ -f "/tmp/phpcsReport$today"  ];then
    ## send mail script
fi
###############


################
##
## 自动生成api doc
##
################

/usr/local/php/bin/php /data/apigen/apigen.php --config /data/apigen/dyact3.config 

###############

/bin/rm -rf $CODE_PATH

