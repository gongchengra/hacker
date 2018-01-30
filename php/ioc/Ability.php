<?php
class Power
{
    /**
        *      * 能力值
        *           */
    protected $ability;

    /**
        *      * 能力范围或距离
        *           */
    protected $range;

    public function __construct($ability, $range)
    {
        $this->ability = $ability;
        $this->range = $range;
    }
}

class Flight
{
    protected $speed;
    protected $holdtime;
    public function __construct($speed, $holdtime)
    {
        $this->speed = $speed;
        $this->holdtime = $holdtime;
    }
    public function showSpeed(){
        echo 'Speed: '.$this->speed."\n";
        echo 'Holdtime: '.$this->holdtime."\n";
    }

}

class Force
{
    protected $force;
    public function __construct($force)
    {
        $this->force = $force;
    }
    public function showForce(){
        echo 'Force: '.$this->force."\n";
    }
}

class Shot
{
    protected $atk;
    protected $range;
    protected $limit;
    public function __construct($atk, $range, $limit)
    {
        $this->atk = $atk;
        $this->range = $range;
        $this->limit = $limit;
    }
    public function showShot(){
        echo 'Atk: '.$this->atk."\n";
        echo 'Range: '.$this->range."\n";
        echo 'Limit: '.$this->limit."\n";
    }

}
