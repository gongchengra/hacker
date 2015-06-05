// author: gongchengra@gmail.com
// http://projecteuler.net/problem=33
// The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
//
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
//
// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
//
// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
// 
// get a clue from
// http://www.mathblog.dk/project-euler-33-fractions-unorthodox-cancelling-method/
var denproduct = 1;
var nomproduct = 1;

for (var i = 1; i < 10; i++) {
    for (var den = 1; den < i; den++) {
        for (var nom = 1; nom < den; nom++) {
            if ((nom * 10 + i) * den == nom * (i * 10 + den)) {
                denproduct *= den;
                nomproduct *= nom;
                console.log((nom * 10 + i) + ' ' + (i * 10 + den));
            }
        }
    }
}
//output
//16 64
//26 65
//19 95
//49 98
//therefore, result should be 1*2*1*1/4*5*5*2 = 1/100
