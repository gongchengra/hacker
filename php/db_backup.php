<?php

error_reporting(E_ALL ^ E_NOTICE);
ini_set('display_errors', 1);
ini_set('memory_limit', '512M');

// Get Magento Application
require_once 'app/Mage.php';
Mage::app('default');

// get Magento config
$config  = Mage::getConfig()->getResourceConnectionConfig("default_setup");

$dbinfo = array(
    'host' => $config->host,
    'user' => $config->username,
    'pass' => $config->password,
    'dbname' => $config->dbname,
);

// Database Config
$db_host = $dbinfo['host'];
$db_user = $dbinfo['user'];
$db_pass = $dbinfo['pass'];
$db_name = $dbinfo['dbname'];

// filename
$backup_file = $db_name."-".date("Y-m-d-H-i-s").".gz";

$command = "mysqldump --database ".$db_name." -u ".$db_user." -p'".$db_pass."' | gzip > ".$backup_file;

echo 'command executing is '.$command.'<br/>';

$output = shell_exec($command);

echo 'Finished!<br/>';
