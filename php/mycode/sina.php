<?php
function checklogin( $user, $password )
{
    $userAgent = isset($_SERVER['HTTP_USER_AGENT']) ? strtolower($_SERVER['HTTP_USER_AGENT']) : '';
    if ( empty( $user ) || empty( $password ) )
    {
        return 0;
    }
    $ch = curl_init( );
    curl_setopt( $ch, CURLOPT_REFERER, "http://mail.sina.com.cn/index.html" );
    curl_setopt( $ch, CURLOPT_HEADER, true );
    curl_setopt( $ch, CURLOPT_RETURNTRANSFER, true );
    curl_setopt( $ch, CURLOPT_USERAGENT, $userAgent);
    curl_setopt( $ch, CURLOPT_COOKIEJAR, tempnam( "/tmp", "cookie" ));
    curl_setopt( $ch, CURLOPT_TIMEOUT, 500);
    curl_setopt( $ch, CURLOPT_URL, "http://mail.sina.com.cn/cgi-bin/login.cgi" );
    curl_setopt( $ch, CURLOPT_POST, true );
    curl_setopt( $ch, CURLOPT_POSTFIELDS, "&logintype=uid&u=".urlencode( $user )."&psw=".$password );
    $contents = curl_exec( $ch );
    curl_close( $ch );
    if ( !preg_match( "/Location: (.*)\\/cgi\\/index\\.php\\?check_time=(.*)\n/", $contents, $matches ) )
    {
        return 0;
    }else{
        return 1;
    }
}

?>
