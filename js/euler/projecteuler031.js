// author: gongchengra@gmail.com
// http://projecteuler.net/problem=31
// In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
//
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// It is possible to make £2 in the following way:
//
// 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
// How many different ways can £2 be made using any number of coins?
var coins = [1, 2, 5, 10, 20, 50, 100, 200];
var coinWays = function coinWays(N, m) {
    if (N === 0) {
        return 1;
    }
    if (N < 0) {
        return 0;
    }
    if (m === 1) {
        return 1;
    } else {
        return coinWays(N, m - 1) + coinWays(N - coins[m - 1], m);
    }
}
console.log(coinWays(200, coins.length)); //73682
console.log(coinWays(1, coins.length)); //1

