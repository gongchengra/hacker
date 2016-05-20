<?php
/**
* @author 简明现代魔法 http://www.nowamagic.net
*/
class Fibonacci implements Iterator {
    private $previous = 1;
    private $current = 0;
    private $key = 0;

    public function current() {
        return $this->current;
    }

    public function key() {
        return $this->key;
    }

    public function next() {
		// 关键在这里
		// 将当前值保存到  $newprevious
        $newprevious = $this->current;
		// 将上一个值与当前值的和赋给当前值
        $this->current += $this->previous;
		// 前一个当前值赋给上一个值
        $this->previous = $newprevious;
        $this->key++;
    }

    public function rewind() {
        $this->previous = 1;
        $this->current = 0;
        $this->key = 0;
    }

    public function valid() {
        return true;
    }
}

$seq = new Fibonacci;
$i = 0;
foreach ($seq as $f) {
    echo "$f ";
    if ($i++ === 35) break;
}
