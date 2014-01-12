//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=21
/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

var inputArray = ["name.txt"];

var getSumOfDigitalInString = function getSumOfDigitalInString(str) {
    var strArray = str.split("");
    return strArray.reduce(function(pre,cur){
        return pre+(cur.charCodeAt(0)-'A'.charCodeAt(0)+1);
    },0);
}

var sum = 0;
inputArray.sort().forEach(function(elem, index, arr){
    sum += (index+1)*getSumOfDigitalInString(elem);
});

console.log(sum);//871198282 
