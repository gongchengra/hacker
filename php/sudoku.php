#!/usr/local/bin/php
<?php
$initArray = array(
    8,0,0,0,0,0,0,0,0,
    0,0,3,6,0,0,0,0,0,
    0,7,0,0,9,0,2,0,0,
    0,5,0,0,0,7,0,0,0,
    0,0,0,0,4,5,7,0,0,
    0,0,0,1,0,0,0,3,0,
    0,0,1,0,0,0,0,6,8,
    0,0,8,5,0,0,0,1,0,
    0,9,0,0,0,0,4,0,0
);
$messageLog = 'sudoku.log';
$message = '';
$tmpArray = array();
$tmpStack = array();

foreach ($initArry as $key => $val) {
    if (0 == $val) {
        $tmpArray[$key] = "123456789";
    } else {
        $tmpArray[$key]= "$val";
    }
}

function calculateSameRcb($tmpKey) {
    $rowNumber = intval($tmpKey / 9);
    $columnNumber = $tmpKey % 9;
    $sameRowArray = array();
    $sameColumnArray = array();
    $sameBlockArray = array();
    for ($counter = 0; $counter < 9; $counter++) {
        $sameRow = $rowNumber * 9 + $counter;
        $sameRowArray[$counter] = $sameRow;
        $sameColumn = $counter * 9 + $columnNumber;
        $sameColumnArray[$counter] = $sameColumn;
        $sameBlock = intval($rowNumber / 3) * 3 * 9 + intval($tmpKey % 9 / 3) * 3;
        $sameBlock += intval($counter / 3) * 9 + $counter % 3;
        $sameBlockArray[$counter] = $sameBlock;
    }
    $rowColumnBlock['row'] = $sameRowArray;
    $rowColumnBlock['column'] = $sameColumnArray;
    $rowColumnBlock['block'] = $sameBlockArray;
    return $rowColumnBlock;
}

function deleteDuplicateValue($tmpArray) {
    do {
        $deleteFlag = false;
        foreach ($tmpArray as $tmpKey => $tmpVal) {
            if (strlen($tmpVal) == 1) {
                $rowColumnBlock = calculateSameRcb($tmpKey);
                $sameRowArray = $rowColumnBlock['row'];
                $sameColumnArray = $rowColumnBlock['column'];
                $sameBlockArray = $rowColumnBlock['block'];
                foreach ($sameRowArray as $sameRowKey) {
                    if ($sameRowKey != $tmpKey && strlen($tmpArray[$sameRowKey]) > 1
                        && false !== strpos($tmpArray[$sameRowKey], $tmpArray[$tmpKey])) {
                        $tmpArray[$sameRowKey] = str_replace($tmpArray[$tmpKey],'',$tmpArray[$sameRowKey]);
                        $deleteFlag = true;
                    }
                }
                foreach ($sameColumnArray as $sameColumnKey) {
                    if ($sameColumnKey != $tmpKey && strlen($tmpArray[$sameColumnKey]) > 1
                        && false !== strpos($tmpArray[$sameColumnKey], $tmpArray[$tmpKey])) {
                        $tmpArray[$sameColumnKey] = str_replace($tmpArray[$tmpKey],'',$tmpArray[$sameColumnKey]);
                        $deleteFlag = true;
                    }
                }
                foreach ($sameBlockArray as $sameBlockKey) {
                    if ($sameBlockKey != $tmpKey && strlen($tmpArray[$sameBlockKey]) > 1
                        && false !== strpos($tmpArray[$sameBlockKey], $tmpArray[$tmpKey])) {
                        $tmpArray[$sameBlockKey] = str_replace($tmpArray[$tmpKey],'',$tmpArray[$sameBlockKey]);
                        $deleteFlag = true;
                    }
                }
            }
        }
    } while (false != $deleteFlag);
    return $tmpArray;
}

function fillCellsWithOnePossibility($tmpArray) {
    do {
       $foundFlag = false;
        foreach ($tmpArray as $tmpKey => $tmpVal) {
            if(strlen($tmpVal) > 1)
            {
                $tmpValArray = str_split($tmpVal);
                foreach ($tmpValArray as $val) {
                    $rowColumnBlock = calculateSameRcb($tmpKey);
                    $sameRowArray = $rowColumnBlock['row'];
                    $sameColumnArray = $rowColumnBlock['column'];
                    $sameBlockArray = $rowColumnBlock['block'];
                    $rowCounter = 0;
                    foreach ($sameRowArray as $sameRowKey) {
                        if (false !== strpos($tmpArray[$sameRowKey], $val)) {
                            $rowCounter++;
                            $rememberRow = $sameRowKey;
                        }
                    }
                    if (1 == $rowCounter && strlen($tmpArray[$rememberRow]) > 1) {
                        $tmpArray[$rememberRow] = "$val";
                        $foundFlag = true;
                    }
                    $columnCounter = 0;
                    foreach ($sameColumnArray as $sameColumnKey) {
                        if (false !== strpos($tmpArray[$sameColumnKey], $val)) {
                            $columnCounter++;
                            $rememberColumn = $sameColumnKey;
                        }
                    }
                    if (1 == $columnCounter && strlen($tmpArray[$rememberColumn]) > 1) {
                        $tmpArray[$rememberColumn] = "$val";
                        $foundFlag = true;
                    }
                    $blockCounter = 0;
                    foreach ($sameBlockArray as $sameBlockKey) {
                        if (false !== strpos($tmpArray[$sameBlockKey], $val)) {
                            $blockCounter++;
                            $remember_block = $sameBlockKey;
                        }
                    }
                    if (1 == $blockCounter && strlen($tmpArray[$remember_block]) > 1) {
                        $tmpArray[$remember_block] = "$val";
                        $foundFlag = true;
                    }
                }
            }
        }
    } while (false != $foundFlag);
    return $tmpArray;
}

function simplifyArray($tmpArray) {
    do {
        $beforeSimplify = $tmpArray;
        $tmpArray = deleteDuplicateValue($tmpArray);
        $tmpArray = fillCellsWithOnePossibility($tmpArray);
        $afterSimplify = $tmpArray;
    } while ($beforeSimplify != $afterSimplify);
    return $tmpArray;
}

function checkArray($tmpArray) {
    foreach ($tmpArray as $tmpKey => $tmpVal) {
        $rowColumnBlock = calculateSameRcb($tmpKey);
        $sameRowArray = $rowColumnBlock['row'];
        $sameColumnArray = $rowColumnBlock['column'];
        $sameBlockArray = $rowColumnBlock['block'];
        if (strlen($tmpVal) == 1)
        {
            foreach ($sameRowArray as $sameRowKey) {
                if ($tmpKey != $sameRowKey && 1 == strlen($tmpArray[$sameRowKey]) && $tmpVal == $tmpArray[$sameRowKey]) {
                    return false;
                }
            }
            foreach ($sameColumnArray as $sameColumnKey) {
                if ($tmpKey != $sameColumnKey && 1 == strlen($tmpArray[$sameColumnKey]) && $tmpVal == $tmpArray[$sameColumnKey]) {
                    return false;
                }
            }
            foreach ($sameBlockArray as $sameBlockKey) {
                if ($tmpKey != $sameBlockKey && 1 == strlen($tmpArray[$sameBlockKey]) && $tmpVal == $tmpArray[$sameBlockKey]) {
                    return false;
                }
            }
        }
    }
    return true;
}

function getArrayStatus($tmpArray) {
    $knownNumber = 0;
    foreach ($tmpArray as $tmpKey => $tmpVal) {
        if (0 == strlen($tmpVal)) {
            return 'error';
        }
        if (1 == strlen($tmpVal)) {
            $knownNumber++;
        }
    }
    if (81 == $knownNumber) {
        return 'solved';
    } else {
        return 'unsolved';
    }
}

function findLeastUnknownCell($tmpArray) {
    $leastUnknownVal = '123456789';
    foreach ($tmpArray as $tmpKey => $tmpVal) {
        if (strlen($tmpVal) > 1 && strlen($tmpVal) < strlen($leastUnknownVal)) {
            $leastUnknownKey = $tmpKey;
            $leastUnknownVal = $tmpVal;
        }
    }
    $leastUnknownCell['key'] = $leastUnknownKey;
    $leastUnknownCell['val'] = $leastUnknownVal;
    return $leastUnknownCell;
}

$tmpArray = simplifyArray($tmpArray);
if (false == checkArray($tmpArray)) {
    echo "No solution";
    $message .= "No solution";
    file_putContents($messageLog, $message);
    exit;
} else {
    do {
        $tmpArrayStatus = getArrayStatus($tmpArray);
        if ('solved' == $tmpArrayStatus) {
            if (true == checkArray($tmpArray))
            {
                foreach ($tmpArray as $key => $value) {
                    if (0 == ($key+1)%9) {
                        $message .= $value."\n";
                    } else {
                        $message .= $value.' ';
                    }
                }
                foreach ($tmpArray as $key => $value) {
                    if (0 == ($key+1)%9){
                        echo $value."\n";
                    } else {
                        echo $value.' ';
                    }
                }
                echo "\n";
            }
            if (0 == count($tmpStack)) {
                break;
            } else {
                $topOfStack = array_pop($tmpStack);
                $tmpArray = array_pop($tmpStack);
                $topOfStackArray = str_split($topOfStack['val']);
                $firstNumberOnTopStack = array_shift($topOfStackArray);
                $tmpArray[$topOfStack['key']] = $firstNumberOnTopStack;
                //echo 'assume '. $leastUnknownCell['key']. ' is '. $firstNumberOnTopStack. "\n";
                $tmpArray = simplifyArray($tmpArray);
                if (count($topOfStackArray) > 0)
                {
                    $topOfStack['val'] = join('',$topOfStackArray);
                    array_push($tmpStack, $tmpArray);
                    array_push($tmpStack, $topOfStack);
                }
            }
        }
        if ('unsolved' == $tmpArrayStatus) {
            array_push($tmpStack, $tmpArray);
            $leastUnknownCell = findLeastUnknownCell($tmpArray);
            $unknownCellArray = str_split($leastUnknownCell['val']);
            $firstNumberInUnknownCell = array_shift($unknownCellArray);
            $leastUnknownCell['val'] = join('',$unknownCellArray);
            array_push($tmpStack,$leastUnknownCell);
            $tmpArray[$leastUnknownCell['key']] = $firstNumberInUnknownCell;
            $tmpArray = simplifyArray($tmpArray);
        }
        if ('error' == $tmpArrayStatus) {
            if (0 == count($tmpStack)) {
                $message .= "No solution";
                break;
            } else {
                $topOfStack = array_pop($tmpStack);
                array_pop($tmpStack);
                $topOfStackArray = str_split($topOfStack['val']);
                $firstNumberOnTopStack = array_shift($topOfStackArray);
                $tmpArray[$topOfStack['key']] = $firstNumberOnTopStack;
                $tmpArray = simplifyArray($tmpArray);
                if (count($topOfStackArray) > 0)
                {
                    $topOfStack['val'] = join('',$topOfStackArray);
                    array_push($tmpStack, $topOfStack);
                }
            }
        }
    } while (1);
}
file_put_contents($messageLog, $message);
