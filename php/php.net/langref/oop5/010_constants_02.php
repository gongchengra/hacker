<?php

abstract class dbObject
{
    const TABLE_NAME = 'undefined';

    public static function GetAll()
    {
        $c = get_called_class();

        return 'SELECT * FROM `'.$c::TABLE_NAME.'`';
    }
}

class dbPerson extends dbObject
{
    const TABLE_NAME = 'persons';
}

class dbAdmin extends dbPerson
{
    const TABLE_NAME = 'admins';
}

echo dbPerson::GetAll().PHP_EOL; //output: "SELECT * FROM `persons`"
echo dbAdmin::GetAll().PHP_EOL; //output: "SELECT * FROM `admins`"
