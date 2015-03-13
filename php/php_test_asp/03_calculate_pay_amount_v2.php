#!/usr/bin/php
<?php
/*
Problem:
Calculate Pay Amount for different types of Employees

A company has 3 types of employees (Engineer, Manager and Sales), the monthly salary of each employee type is calculated by following format:

Engineer = month_salary;
Manager = month_salary + bonus;
Sales = (month_salary * commission) / 2000;

This company has following two existing tables which recording its employees as blow:

employee table
employee_id
name
employee_type_id
month_salary
commission
bonus
1
Wang
1
8000


2
Zhang
2
10000

2000
3
Zhao
3
6000
2000


employee_type table
employee_type_id
type
1
Engineer
2
Manager
3
Sales

Now, please program some code, which could calculate all employee’s monthly pay amount by his (her) Employee ID.

Tips:
1). OOP is required to implement this feature.
2). you can create new classes as well as using existing php functions.
3). There are more than two ways applicable to this request. High extendable solution is highly desired which could be adaptable with more employee types and salary format in the future.
4). Assume an existing Static function Database::GetRow($sql) can be used to retrieve a row of a table from database.



The input is $employee_id, please print out the salary of this employee.

Answer:

Author:     gongcheng_ph@hotmail.com
Version:    v2
Date:       2013-06-09
Desc:       Calculate Pay Amount for different types of Employees.
        The input is $employee_id, please print out the salary of this employee.
*/
/* creat table in mysql for test:
CREATE TABLE IF NOT EXISTS `employee` (
  `employee_id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(250) NOT NULL DEFAULT '',
  `employee_type_id` smallint(5) unsigned NOT NULL,
  `month_salary` decimal(10.2) NOT NULL,
  `commission` decimal(10.2),
  `bonus` decimal(10.2),
  PRIMARY KEY (`employee_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `test`.`employee` (`employee_id`, `name`, `employee_type_id`, `month_salary`, `commission`, `bonus`) VALUES ('1', 'Wang', '1', '8000', NULL, NULL);
INSERT INTO `test`.`employee` (`employee_id`, `name`, `employee_type_id`, `month_salary`, `commission`, `bonus`) VALUES ('2', 'Zhang', '2', '10000', NULL, '2000');
INSERT INTO `test`.`employee` (`employee_id`, `name`, `employee_type_id`, `month_salary`, `commission`, `bonus`) VALUES ('3', 'Zhao', '3', '6000', '2000', NULL);

CREATE TABLE IF NOT EXISTS `employee_type` (
  `employee_type_id` smallint(5) unsigned NOT NULL,
  `type` varchar(250) NOT NULL DEFAULT '',
  PRIMARY KEY (`employee_type_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `test`.`employee_type` (`employee_type_id`, `type`) VALUES ('1', 'Engineer');
INSERT INTO `test`.`employee_type` (`employee_type_id`, `type`) VALUES ('2', 'Manager');
INSERT INTO `test`.`employee_type` (`employee_type_id`, `type`) VALUES ('3', 'Sales');


*/

// database host
$db_host   = "localhost";
// database username
$db_user   = "root";
// database password
$db_pass   = "root";
// database name
$db_name   = "test";

// Function to retrieve a row of a table from database.
function GetRow($db_host, $db_user, $db_pass, $db_name, $sql)
{
    $link = mysqli_connect($db_host, $db_user, $db_pass, $db_name)
    or die("Could not select database because ".mysqli_error($link));
    $result = mysqli_query($link, $sql) or die("Could not match data because ".mysqli_error($link));
    $result_array = mysqli_fetch_array($result);
    mysqli_close($link);

    return $result_array;
}

abstract class Employer
{
    public $name;
    public $employee_id;
    public $employee_type_id;
    public $month_salary;
    public $commission;
    public $bonus;
    public $salary;

    public function __construct($result)
    {
        $this->name = $result['name'];
        $this->employee_id = $result['employee_id'];
        $this->employee_type_id = $result['employee_type_id'];
        $this->month_salary = $result['month_salary'];
        $this->commission = $result['commission'];
        $this->bonus = $result['bonus'];
    }

    abstract public function salary_calculation();
}

class Engineer extends Employer
{
    public function salary_calculation()
    {
        $this->salary = $this->month_salary;
    }
}

$employee_id = '1';
$sql = "SELECT * FROM employee WHERE employee_id = ".$employee_id;
$result = GetRow($db_host, $db_user, $db_pass, $db_name, $sql);
$engineer = new Engineer($result);
$engineer->salary_calculation();
print $engineer->salary.PHP_EOL;

class Manager extends Employer
{
    public function salary_calculation()
    {
        $this->salary = $this->month_salary + $this->bonus;
    }
}

$employee_id = '2';
$sql = "SELECT * FROM employee WHERE employee_id = ".$employee_id;
$result = GetRow($db_host, $db_user, $db_pass, $db_name, $sql);
$manager = new Manager($result);
$manager->salary_calculation();
print $manager->salary.PHP_EOL;

class Sale extends Employer
{
    public function salary_calculation()
    {
        $this->salary = (($this->month_salary) * ($this->commission))/2000;
    }
}

$employee_id = '3';
$sql = "SELECT * FROM employee WHERE employee_id = ".$employee_id;
$result = GetRow($db_host, $db_user, $db_pass, $db_name, $sql);
$sale = new Sale($result);
$sale->salary_calculation();
print $sale->salary.PHP_EOL;
