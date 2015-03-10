<?php
/**
 * 数据访问对象(Data Access Object) 示例
 *
 * @create_date: 2010-01-04
 */

class BaseDAO
{
    public $_db = null;
    public $_table = null;

    public function BaseDAO($config)
    {
        $this->_db = new MysqlDB(); // 这里的不能进行操作
    }

    /**
     * 获取处理
     *
     * @param array  $filter // 过滤条件
     * @param string $field  // 获取字段
     * @param int    $page   // 当前页
     * @param int    $limit  // 页数
     */
    public function fetch($filter = array(), $field = "*", $page = 1, $limit = null)
    {
        $this->_db->select($filed)->from($this->_table)->where($filter)->limit($page, $limit);

        return $this->_db->execute();
    }

    public function update()
    {
    }
    public function delete()
    {
    }
    public function insert()
    {
    }
}

class MemberDAO extends BaseDAO
{
    public $_table = "member";
}

$oMember = new MemberDAO();
$oMember->fetch();

/**
 * 常用到的地方:
 * MVC中model层基类
 */;
