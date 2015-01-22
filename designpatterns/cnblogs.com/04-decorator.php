<?php
/**
 * 装饰模式
 *
 * 动态的给一个对象添加一些额外的职责,就扩展功能而言比生成子类方式更为灵活
 */
header("Content-type:text/html;charset=utf-8");
abstract  class  MessageBoardHandler
{
    public function __construct(){}
        abstract public function filter($msg);
}

class  MessageBoard extends MessageBoardHandler
{
    public function filter($msg)
    {
        return "处理留言板上的内容|".$msg;
    }
}

$obj=new MessageBoard();
echo$obj->filter("一定要学好装饰模式<br/>");

// --- 以下是使用装饰模式 ----
class  MessageBoardDecorator extends MessageBoardHandler
{
    private$_handler=null;

    public function __construct($handler)
    {
        parent::__construct();
        $this->_handler =$handler;
    }

    public function filter($msg)
    {
        return $this->_handler->filter($msg);
    }
}

// 过滤html
class  HtmlFilter extends MessageBoardDecorator
{
    public function __construct($handler)
    {
        parent::__construct($handler);
    }

    public function filter($msg)
    {
        return "过滤掉HTML标签|".parent::filter($msg);; // 过滤掉HTML标签的处理 这时只是加个文字 没有进行处理
    }
}

// 过滤敏感词
class  SensitiveFilter extends MessageBoardDecorator
{
    public function __construct($handler)
    {
        parent::__construct($handler);
    }

    public function filter($msg)
    {
        return "过滤掉敏感词|".parent::filter($msg); // 过滤掉敏感词的处理 这时只是加个文字 没有进行处理
    }
}

$obj=new HtmlFilter(new SensitiveFilter(new MessageBoard()));
echo$obj->filter("一定要学好装饰模式!<br/>");
