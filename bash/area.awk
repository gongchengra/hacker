#!/bin/awk -f
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
