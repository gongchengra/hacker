<?php
if(isset($_POST['testInput'])){
    $input = intval($_POST['testInput']);
    print $input*$input;
}
