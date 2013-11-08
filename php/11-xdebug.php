<?php
xdebug_start_trace();
function squareNumber($number) {
  return $number * $numbr;
}
?>
<html>
<head>
<title>Xdebug test 1</title>
</head>
<body>
<table>
<tr><td>Number</td><td>Number Squared</td></tr>
<?php
  for ($i=0; $i<5; $i++) {
      echo '<tr><td>'.$i.'</td><td>'.squareNumber($i).'</td></tr>';
    }
?>
</table>
</body>
</html>
