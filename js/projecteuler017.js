//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=17
/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/
var unit = function unit(num) {
	var letters = 0;
	switch (num) {
	case 1:
		letters += 3;
		break;
	case 2:
		letters += 3;
		break;
	case 3:
		letters += 5;
		break;
	case 4:
		letters += 4;
		break;
	case 5:
		letters += 4;
		break;
	case 6:
		letters += 3;
		break;
	case 7:
		letters += 5;
		break;
	case 8:
		letters += 5;
		break;
	case 9:
		letters += 4;
		break;
	default:
		break;
	}
	return letters;
}

var tenTonineteen = function tenTonineteen(num) {
	var letters = 0;
	switch (num) {
	case 10:
		letters += 3;
		break;
	case 11:
		letters += 6;
		break;
	case 12:
		letters += 6;
		break;
	case 13:
		letters += 8;
		break;
	case 14:
		letters += 8;
		break;
	case 15:
		letters += 7;
		break;
	case 16:
		letters += 7;
		break;
	case 17:
		letters += 9;
		break;
	case 18:
		letters += 8;
		break;
	case 19:
		letters += 8;
		break;
	default:
		break;
	}
	return letters;
}

var tens = function tens(num) {
	var letters = 0;
	switch (num) {
	case 2:
		letters += 6;
		break;
	case 3:
		letters += 6;
		break;
	case 4:
		letters += 5;
		break;
	case 5:
		letters += 5;
		break;
	case 6:
		letters += 5;
		break;
	case 7:
		letters += 7;
		break;
	case 8:
		letters += 6;
		break;
	case 9:
		letters += 6;
		break;
	default:
		break;
	}
	return letters;
}

var calculateLetters = function calculateLetters() {
	var i;
	var letters = 0;
	var hundred;
	for (i = 1; i < 100; i++) {
		if (i < 10) {
			letters += unit(i);
		} else if (i < 20) {
			letters += tenTonineteen(i);
		} else {
			letters += tens(parseInt(i / 10));
			letters += unit(i % 10);
		}
	}
	hundred = letters;
	for (i = 1; i < 10; i++) {
		//100 one handred, i.e. unit(1) + 7
		//101 one handred and one, i.e. unit(1) + 7 + 3 
		//101 to 109, thus multiply by 99
		letters += unit(i) + 7 + (unit(i) + 7 + 3) * 99 + hundred;
	}
	letters += 11; // one thousand
	return letters;
}

console.log(calculateLetters());

