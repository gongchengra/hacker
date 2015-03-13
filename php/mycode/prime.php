#!/usr/local/bin/php
<?php
if($argc != 2 || in_array($argv[1], array('--help', '-help', '-h', '-?')))
{
    echo "Useage: Input a number N, it will return N prime numbers start from 2: \n";
    echo "For example, ". $argv[0]. " 5 will return 2, 3, 5, 7, 11\n";
}
else
{
    //According to Prime_number_theorem, the N prime number is approximately N*log(N)
    function getFirstNPrimeNumbers($N) {
        $resultArray = Array();
        if($N < 1) {
            $resultArray = 'Invalid argument.';
        } else if ($N == 1) {
            $resultArray[] = '2';
        } else {
            $primeArray = Array();
            if($N < 20) {
                $MaxNumber = intval(3*$N*log($N));
            } else {
                $MaxNumber = intval(1.2*$N*log($N));
            }
            for($i = 0;$i < $MaxNumber;$i++){
                $primeArray[$i]=true;
            }
            $sqrtMax = sqrt($MaxNumber);
            for($i=0;$i<=$sqrtMax;$i++) {
                if($primeArray[$i] == true) {
                    for($j=$i+2;$j<$MaxNumber;$j++){
                        if(($j+2)%($i+2) == 0) {
                            $primeArray[$j] = false;
                        }
                    }
                }
            }
            for($i=0;$i<$MaxNumber,sizeof($resultArray) < $N;$i++) {
                if($primeArray[$i] == true) {
                    array_push($resultArray,$i+2);
                }
            }
        }
        return $resultArray;
    }
    print_r(getFirstNPrimeNumbers(intval($argv[1])));
}
