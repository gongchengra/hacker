#!/usr/bin/php
<?php
function dashesToCamelCase($string, $capitalizeFirstCharacter = false)
{
    $str = str_replace(' ', '', ucwords(str_replace('-', ' ', $string)));

    if (!$capitalizeFirstCharacter) {
        $str[0] = strtolower($str[0]);
    }

    return $str;
}

echo dashesToCamelCase('this-is-a-string')."\n";

function camelize($input, $separator = '_')
{
    return str_replace($separator, '', ucwords($input, $separator));
}

echo camelize('this_is_a_string')."\n";

function dashesToCamelCasePreg($string, $capitalizeFirstCharacter = false)
{
    return preg_replace_callback('/-[a-zA-Z]/', 'removeDashAndCapitalize', $string);
}

function removeDashAndCapitalize($matches)
{
    return strtoupper($matches[0][1]);
}

echo dashesToCamelCasePreg('this-is-a-string')."\n";

function camelCase($str)
{
    $i = array('-', '_');
    $str = preg_replace('/([a-z])([A-Z])/', '\\1 \\2', $str);
    $str = preg_replace('@[^a-zA-Z0-9\-_ ]+@', '', $str);
    $str = str_replace($i, ' ', $str);
    $str = str_replace(' ', '', ucwords(strtolower($str)));
    $str = strtolower(substr($str, 0, 1)).substr($str, 1);

    return $str;
}

function uncamelCase($str)
{
    $str = preg_replace('/([a-z])([A-Z])/', '\\1_\\2', $str);
    $str = strtolower($str);

    return $str;
}

$camel = camelCase('James_LIKES-camelCase');
$uncamel = uncamelCase($camel);
echo $camel.' '.$uncamel."\n";

$tests = array(
    'simpleTest' => 'simple_test',
    'easy' => 'easy',
    'HTML' => 'html',
    'simpleXML' => 'simple_xml',
    'PDFLoad' => 'pdf_load',
    'startMIDDLELast' => 'start_middle_last',
    'AString' => 'a_string',
    'Some4Numbers234' => 'some4_numbers234',
    'TEST123String' => 'test123_string',
);

foreach ($tests as $test => $result) {
    $output = from_camel_case($test);
    if ($output === $result) {
        echo "Pass: $test => $result\n";
    } else {
        echo "Fail: $test => $result [$output]\n";
    }
}

function from_camel_case($input)
{
    preg_match_all('!([A-Z][A-Z0-9]*(?=$|[A-Z][a-z0-9])|[A-Za-z][a-z0-9]+)!', $input, $matches);
    $ret = $matches[0];
    foreach ($ret as &$match) {
        $match = $match == strtoupper($match) ? strtolower($match) : lcfirst($match);
    }

    return implode('_', $ret);
}
