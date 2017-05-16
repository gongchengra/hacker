<?php
// 我们将要定义自己的错误处理
error_reporting(0);

// 用户自定义错误处理函数
function userErrorHandler($errno, $errmsg, $filename, $linenum, $vars) 
{
    // 错误发生的时间
    $dt = date("Y-m-d H:i:s (T)");

    // 定义错误字符串的关联数组
    // 在这里我们只考虑
    // E_WARNING, E_NOTICE, E_USER_ERROR,
    // E_USER_WARNING 和 E_USER_NOTICE
    $errortype = array (
                E_ERROR              => 'Error',
                E_WARNING            => 'Warning',
                E_PARSE              => 'Parsing Error',
                E_NOTICE             => 'Notice',
                E_CORE_ERROR         => 'Core Error',
                E_CORE_WARNING       => 'Core Warning',
                E_COMPILE_ERROR      => 'Compile Error',
                E_COMPILE_WARNING    => 'Compile Warning',
                E_USER_ERROR         => 'User Error',
                E_USER_WARNING       => 'User Warning',
                E_USER_NOTICE        => 'User Notice',
                E_STRICT             => 'Runtime Notice',
                E_RECOVERABLE_ERROR  => 'Catchable Fatal Error'
                );
    // 设置要保存变量跟踪信息的错误类别
    $user_errors = array(E_USER_ERROR, E_USER_WARNING, E_USER_NOTICE);
    
    $err = "<errorentry>\n";
    $err .= "\t<datetime>" . $dt . "</datetime>\n";
    $err .= "\t<errornum>" . $errno . "</errornum>\n";
    $err .= "\t<errortype>" . $errortype[$errno] . "</errortype>\n";
    $err .= "\t<errormsg>" . $errmsg . "</errormsg>\n";
    $err .= "\t<scriptname>" . $filename . "</scriptname>\n";
    $err .= "\t<scriptlinenum>" . $linenum . "</scriptlinenum>\n";

    if (in_array($errno, $user_errors)) {
        $err .= "\t<vartrace>" . wddx_serialize_value($vars, "Variables") . "</vartrace>\n";
    }
    $err .= "</errorentry>\n\n";
    
    // for testing
    // echo $err;

    // 记录错误信息到错误日志，并在发生关键用户错误时发送电子邮件
    error_log($err, 3, "/usr/local/php4/error.log");
    if ($errno == E_USER_ERROR) {
        mail("phpdev@example.com", "Critical User Error", $err);
    }
}


function distance($vect1, $vect2) 
{
    if (!is_array($vect1) || !is_array($vect2)) {
        trigger_error("Incorrect parameters, arrays expected", E_USER_ERROR);
        return NULL;
    }

    if (count($vect1) != count($vect2)) {
        trigger_error("Vectors need to be of the same size", E_USER_ERROR);
        return NULL;
    }

    for ($i=0; $i<count($vect1); $i++) {
        $c1 = $vect1[$i]; $c2 = $vect2[$i];
        $d = 0.0;
        if (!is_numeric($c1)) {
            trigger_error("Coordinate $i in vector 1 is not a number, using zero", 
                            E_USER_WARNING);
            $c1 = 0.0;
        }
        if (!is_numeric($c2)) {
            trigger_error("Coordinate $i in vector 2 is not a number, using zero", 
                            E_USER_WARNING);
            $c2 = 0.0;
        }
        $d += $c2*$c2 - $c1*$c1;
    }
    return sqrt($d);
}

$old_error_handler = set_error_handler("userErrorHandler");

// 未定义的常量，将产生一个警告
$t = I_AM_NOT_DEFINED;

// 定义一些 "载体"
$a = array(2, 3, "foo");
$b = array(5.5, 4.3, -1.6);
$c = array(1, -3);

// 引发一个用户错误
$t1 = distance($c, $b) . "\n";

// 再次引发一个用户错误
$t2 = distance($b, "i am not an array") . "\n";

// 引发一个警告
$t3 = distance($a, $b) . "\n";