<?php
final class BaseClass
{
    public function test() {
        echo "BaseClass::test() called\n";
    }

    // 这里无论你是否将方法声明为final，都没有关系
    final public function moreTesting() {
        echo "BaseClass::moreTesting() called\n";
    }
}

class ChildClass extends BaseClass {
}
// 产生 Fatal error: Class ChildClass may not inherit from final class (BaseClass)
