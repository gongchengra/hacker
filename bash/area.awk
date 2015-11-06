#!/bin/awk -f
# For the source in http://www.stats.gov.cn/tjsj/tjbz/xzqhdm/201504/t20150415_712722.html
# We get the province, city, area code and name, save as "data" like the following:
# 110000  　北京市
# 110100  　　市辖区
# 110101  　　　东城区
# 110200  　　县
# 110228  　　　密云县
# 110229  　　　延庆县
# 120000  　天津市
# 120100  　　市辖区
# 120101  　　　和平区
# 120102  　　　河东区
# By `sed 's/\s\+/ /g' data|awk -f area.awk > area.php`, we get:
# <?php
# $arrCountyList["北京市"]["市辖区"][]="东城区";
# $arrCountyList["北京市"]["县"][]="密云县";
# $arrCountyList["北京市"]["县"][]="延庆县";
# $arrCountyList["天津市"]["市辖区"][]="和平区";
# $arrCountyList["天津市"]["市辖区"][]="河东区";
# $arrCountyList["天津市"]["市辖区"][]="";
# echo json_encode($arrCountyList);
# in area.php, run `php area.php`, we get desired json format.

BEGIN{print "<?php"}
{
    if($1 ~ /[0-9][0-9]0000/)
        P=$2;
    else if($1 ~ /[0-9][0-9][0-9][0-9]00/)
        C=$2;
    else
        print "$arrCountyList[\""P"\"][\""C"\"][]=\""$2"\";";
}
END {print "echo json_encode($arrCountyList);";}
