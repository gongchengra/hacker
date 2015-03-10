<?php
/**
 * 代理模式
 *
 * 为其他对象提供一个代理以控制这个对象的访问
 *
 */
/**
 *  抽象主题角色(Subject):天气
 *
 */
interface Weather
{
    public function request($city);
    public function display($city);
    public function isValidCity($city);
}
/**
 * 真实主题角色(RealSubject):
 *
 */
class RealWeather implements Weather
{
    protected $_url = 'http://www.google.com/ig/api?&oe=utf-8&hl=zh-cn&weather=';
    protected $_weatherXml = '' ;
    function __construct(){
    }
    public function request($city){
        $this->_weatherXml = file_get_contents($this->_url . $city );
    }
    public function display($city ){
        if ($this->_weatherXml == '') {
            $this->request($city);
        }
        //$this->_weatherXml = mb_convert_encoding($this->_weatherXml, 'UTF-8', 'GB2312');
        $weatherxml = simplexml_load_string($this->_weatherXml);
        $low = intval($weatherxml->weather->forecast_conditions[0]->low->attributes());
        $high = $weatherxml->weather->forecast_conditions[0]->high->attributes();
        $icon= 'http://www.google.com'. $weatherxml->weather->forecast_conditions[0]->icon->attributes();
        $condition=$weatherxml->weather->forecast_conditions[0]->condition->attributes();
        $weather = date('Y年n月j日').'  天气预报：<span class="cor_ff6c00 f_bold">'.$city_names[$city].' </span>  <img class="v_middle" src="'.$icon.'" alt="'.$condition.'" width="16" height="17" align="absmiddle" /> <span class="f_bold"></span>：    '.$low.'°C ~ '.$high.'°C '.$condition;
        echo  $weather;
    }
    public function isValidCity($city){
    }
}
/**
 * 代理角色(Proxy):延迟代理
 *
 */
class ProxyWeather  implements Weather {
    private $_client ;
    private function client() {
        if (! $this->_client instanceof RealWeather) {
            $this->_client = new RealWeather();
        }
        return $this->_client;
    }
    public function request($city){
        $this->_client()->request($city);
    }
    public function isValidCity($city) {
        return $this->_client()->isValidCity($city);
    }
    public function display($city) {
        return $this->client()->display($city);
    }
}
/**
 * 代理角色(Proxy):动态代理
 *
 */
class GenericProxyWeather {
    protected $_subject;
    public function __construct($subject) {
        $this->_subject = $subject;
    }
    public function __call($method, $args) {
        return call_user_func_array(
                array($this->_subject, $method),
                $args);
    }
}
class Client{
    static function main(){
        $proxy = new ProxyWeather();
        $report = $proxy->display('beijing');
    }
    static function Genericmain(){
        $proxy = new GenericProxyWeather(new RealWeather());
        $report = $proxy->display('beijing');
    }
}
header('Content-type:text/html;charset=UTF-8');
Client::main();
//Client::Genericmain();

