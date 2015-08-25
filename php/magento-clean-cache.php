<?php

## Function to set file permissions to 0644 and folder permissions to 0755

function AllDirChmod($dir = "./", $dirModes = 0755, $fileModes = 0644)
{
    $d = new RecursiveDirectoryIterator($dir);
    foreach (new RecursiveIteratorIterator($d, 1) as $path) {
        if ($path->isDir()) {
            chmod($path, $dirModes);
        } elseif (is_file($path)) {
            chmod($path, $fileModes);
        }
    }
}

## Function to clean out the contents of specified directory

function cleandir($dir)
{
    if ($handle = opendir($dir)) {
        while (false !== ($file = readdir($handle))) {
            if ($file != '.' && $file != '..' && is_file($dir.'/'.$file)) {
                if (unlink($dir.'/'.$file)) {
                } else {
                    echo $dir.'/'.$file." (file) NOT deleted!\n";
                }
            } elseif ($file != '.' && $file != '..' && is_dir($dir.'/'.$file)) {
                cleandir($dir.'/'.$file);
                if (rmdir($dir.'/'.$file)) {
                } else {
                    echo $dir.'/'.$file." (directory) NOT deleted!\n";
                }
            }
        }
        closedir($handle);
    }
}

function isDirEmpty($dir)
{
    return (($files = @scandir($dir)) && count($files) <= 2);
}

echo "----------------------- CLEANUP START -------------------------\n";
$start = (float) array_sum(explode(' ', microtime()));
echo "\n*************** SETTING PERMISSIONS ***************\n";
echo "Setting all folder permissions to 755\n";
echo "Setting all file permissions to 644\n";
AllDirChmod(".");
echo "Setting pear permissions to 550\n";
chmod("pear", 550);

echo "\n****************** CLEARING CACHE ******************\n";

if (file_exists("var/cache")) {
    echo "Clearing var/cache\n";
    cleandir("var/cache");
}

if (file_exists("var/session")) {
    echo "Clearing var/session\n";
    cleandir("var/session");
}

if (file_exists("var/minifycache")) {
    echo "Clearing var/minifycache\n";
    cleandir("var/minifycache");
}

if (file_exists("downloader/pearlib/cache")) {
    echo "Clearing downloader/pearlib/cache\n";
    cleandir("downloader/pearlib/cache");
}

if (file_exists("downloader/pearlib/download")) {
    echo "Clearing downloader/pearlib/download\n";
    cleandir("downloader/pearlib/download");
}

if (file_exists("downloader/pearlib/pear.ini")) {
    echo "Removing downloader/pearlib/pear.ini\n";
    unlink("downloader/pearlib/pear.ini");
}

echo "\n************** CHECKING FOR EXTENSIONS ***********\n";
if (!isDirEmpty("app/code/local/")) {
    echo "-= WARNING =- Overrides or extensions exist in the app/code/local folder\n";
}
if (!isDirEmpty("app/code/community/")) {
    echo "-= WARNING =- Overrides or extensions exist in the app/code/community folder\n";
}
$end = (float) array_sum(explode(' ', microtime()));
echo "\n------------------- CLEANUP COMPLETED in:".sprintf("%.4f", ($end-$start))." seconds ------------------\n";
