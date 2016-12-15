<?php
var_dump((bool) "");        // bool(false)
var_dump((bool) 1);         // bool(true)
var_dump((bool) -2);        // bool(true)
var_dump((bool) "foo");     // bool(true)
var_dump((bool) 2.3e5);     // bool(true)
var_dump((bool) array(12)); // bool(true)
var_dump((bool) array());   // bool(false)
var_dump((bool) "false");   // bool(true)
/*
 * 当转换为 boolean 时，以下值被认为是 FALSE：
 *
 * 布尔值 FALSE 本身
 * 整型值 0（零）
 * 浮点型值 0.0（零）
 * 空字符串，以及字符串 "0"
 * 不包括任何元素的数组
 * 不包括任何成员变量的对象（仅 PHP 4.0 适用）
 * 特殊类型 NULL（包括尚未赋值的变量）
 * 从空标记生成的 SimpleXML 对象
