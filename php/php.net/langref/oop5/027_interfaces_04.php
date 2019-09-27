<?php

interface a
{
    const b = 'Interface constant';
}

// 输出接口常量
echo a::b;

// 错误写法，因为常量不能被覆盖。接口常量的概念和类常量是一样的。
//class b implements a
//{
//    const b = 'Class constant';
//}
