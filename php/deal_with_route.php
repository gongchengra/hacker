<?php
$routes = file_get_contents('routes.php');
$aRoutes = explode("\n", $routes);
$sPrefixUrl = 'http://homestead.app/';
$sPrefixController = 'App\Http\Controllers\V1_0';
$namespace = 'V1_0';
$prefix = 'hft/1.0';
echo 'url,controller,function'."\n";
foreach($aRoutes as $sRoutes) {
    if(preg_match("/namespace' => '([^']*)', 'prefix' => '([^']*)'/", $sRoutes, $matches)>0){
        if($matches[1] != $namespace) {
            $namespace = $matches[1];
        }
        if($matches[2] != $prefix) {
            $prefix = $matches[2];
        }
    }
    if(preg_match("/get\('([^']*)', '([^@]*)@([^']*)'\)/", $sRoutes, $urls) > 0
        ||preg_match("/post\('([^']*)', '([^@]*)@([^']*)'\)/", $sRoutes, $urls) > 0){
        $url = $urls[1];
        $Controller = $urls[2];
        $Function = $urls[3];
        echo $sPrefixUrl.$prefix.'/'.$url.','.$sPrefixController.'\\'.$Controller.','.$Function."\n";
    }
}

