<?php
/**
 * 组合模式
 *
 * 将对象组合成树形结构以表示"部分-整体"的层次结构,使得客户对单个对象和复合对象的使用具有一致性
 */
abstract class MenuComponent
{
    public function add($component)
    {
    }
    public function remove($component)
    {
    }
    public function getName()
    {
    }
    public function getUrl()
    {
    }
    public function display()
    {
    }
}

class Menu extends MenuComponent
{
    private $_items = array();
    private $_name = null;

    public function __construct($name)
    {
        $this->_name = $name;
    }

    public function add($component)
    {
        $this->_items[] = $component;
    }

    public function remove($component)
    {
        $key = array_search($component, $this->_items);
        if ($key !== false) {
            unset($this->_items[$key]);
        }
    }

    public function display()
    {
        echo "-- ".$this->_name." ---------".PHP_EOL;
        foreach ($this->_items as$item) {
            $item->display();
        }
    }
}

class Item extends MenuComponent
{
    private $_name = null;
    private $_url = null;

    public function __construct($name, $url)
    {
        $this->_name = $name;
        $this->_url = $url;
    }

    public function display()
    {
        echo $this->_name."#".$this->_url.PHP_EOL;
    }
}

class Client
{
    private $_menu = null;

    public function __construct($menu)
    {
        $this->_menu = $menu;
    }

    public function setMenu($menu)
    {
        $this->_menu = $menu;
    }

    public function displayMenu()
    {
        $this->_menu->display();
    }
}

// 实例一下
// 创建menu
$subMenu1 = new Menu("sub menu1");
$subMenu2 = new Menu("sub menu2");
$subMenu3 = new Menu("sub menu3");

$item1 = new Item("163", "www.163.com");
$item2 = new Item("sina", "www.sina.com");

$subMenu1->add($item1);
$subMenu1->add($item2);

$item3 = new Item("baidu", "www.baidu.com");
$item4 = new Item("google", "www.google.com");
$subMenu2->add($item3);
$subMenu2->add($item4);

$allMenu = new Menu("All Menu");
$allMenu->add($subMenu1);
$allMenu->add($subMenu2);
$allMenu->add($subMenu3);

$objClient = new Client($allMenu);
$objClient->displayMenu();

$objClient->setMenu($subMenu2);
$objClient->displayMenu();
