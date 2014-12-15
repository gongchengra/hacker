<?php
require_once "vendor/autoload.php";
require_once "../../conn.php";
$config = new \Doctrine\DBAL\Configuration();
$connectionParams = array(
    'dbname' => $dbname,
    'user' => $dbuser,
    'password' => $dbpass,
    'host' => $dbhost,
    'driver' => 'pdo_mysql',
);
$conn = \Doctrine\DBAL\DriverManager::getConnection($connectionParams, $config);

//$sql = "insert into images (image_name, image_md, upload_time) values ('5482d88e3293d.jpg', '464264f393f31081577b34ee26be0064','2014-12-06');";
$sql = "select * from images;";
$result = $conn->query($sql);
while ($row = $result->fetch()) {
    print $row['image_id'].' '.$row['image_md'].' '.$row['upload_time'];
}

//$sql = "select image_md from images where image_md = '564264f393f31081577b34ee26be0064'";
//$result = $conn -> query($sql);
//if($result -> rowCount() > 0){
//    echo 'already in database';
//}else{
//    echo 'insert please';
//}

//$sql = "select image_md from images where image_md = ?";
//$id = '564264f393f31081577b34ee26be0064';
//$result = $conn->prepare($sql);
//$result->bindValue(1, $id);
//$result->execute();
//if($result -> rowCount() > 0){
//    echo 'already in database';
//}else{
//    echo 'insert please';
//}
