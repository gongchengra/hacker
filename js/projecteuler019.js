//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=19
/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

var day = 1;
var match = 0;
for(var year = 1901; year < 2001; year++) {
    for(var month = 1; month <= 12; month++) {
        var date = new Date(year+'-'+month+'-'+day);
        if(date.getDay() === 0) {
            match++;
        }
    } 
}

console.log(match); //171
