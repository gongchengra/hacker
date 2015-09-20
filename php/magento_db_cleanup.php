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

// Connect to the database
    $dbconn = new mysqli($db_host, $db_user, $db_pass, $db_name);

    if (!$dbconn) {
        die();
    }

echo 'Starting <br>';

$tables = array(
    'dataflow_batch_export',
    'dataflow_batch_import',
    'log_customer',
    'log_quote',
    'log_summary',
    'log_summary_type',
    'log_url',
    'log_url_info',
    'log_visitor',
    'log_visitor_info',
    'log_visitor_online',
    'index_event',
    'report_event',
    'report_viewed_product_index',
    'report_compared_product_index',
    'catalog_compare_item',
    'catalogindex_aggregation',
    'catalogindex_aggregation_tag',
    'catalogindex_aggregation_to_tag',
);

foreach ($tables as $table) {
    $query = 'TRUNCATE TABLE  `'.$table.'`';
    echo $query.'<br>';
    $result = $dbconn->query($query);

    if (!$result) {
        echo 'error clearing '.$table.'<br>';
    } else {
        echo 'cleared '.$table.'<br>';
    }
}

echo 'finished';
