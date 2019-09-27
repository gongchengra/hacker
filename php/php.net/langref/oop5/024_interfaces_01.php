<?php

// 声明一个'iTemplate'接口
interface iTemplate
{
    public function setVariable($name, $var);

    public function getHtml($template);
}

// 实现接口
// 下面的写法是正确的
class Template implements iTemplate
{
    private $vars = array();

    public function setVariable($name, $var)
    {
        $this->vars[$name] = $var;
    }

    public function getHtml($template)
    {
        foreach ($this->vars as $name => $value) {
            $template = str_replace('{'.$name.'}', $value, $template);
        }

        return $template;
    }
}

// 下面的写法是错误的，会报错，因为没有实现 getHtml()：
// Fatal error: Class BadTemplate contains 1 abstract methods
// and must therefore be declared abstract (iTemplate::getHtml)
//class BadTemplate implements iTemplate
//{
//    private $vars = array();

//    public function setVariable($name, $var)
//    {
//        $this->vars[$name] = $var;
//    }
//}
$obj = new template();
$obj->setVariable('name', 'Alan');
$obj->setVariable('say', 'I love you!');
echo $obj->getHtml('hello, {name}! {say}');
