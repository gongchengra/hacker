/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : 18_2048.c

* Author : gongchengra@gmail.com

* Purpose :

* Creation Date : 2015-06-28

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

// Original file by Jay Chan:
// https://gist.github.com/justecorruptio/9967738

#include <stdio.h>
#define GRID_LEN 16

int M[GRID_LEN];
int X = GRID_LEN;
int W;
int k;

int K[] = {2, 3, 1};

s(f, d, i, j, l, P) {
    for(i = 4; i--;) {
        for(j = k = l = 0; k < 4;) {
            if(j < 4) {
                P = M[w(d, i, j++)];
                W |= P >> 11;
                l * P && (f ? M[w(d, i, k)] = l << (l == P) : 0, k++);
                l = l ? (P ? (l-P ? P : 0) : l) : P;
            }
            else {
                f ? M[ w(d, i, k) ] = l : 0;
                ++k;
                W |= 2 * !l;
                l = 0;
            }
        }
    }
}

int w(d, i, j) {

// Decrements until d reaches 0

// Recursive function

    if(d <= 0) {
        return 4 * i + j;
    }

    return w(d - 1, j, 3 - i);
}

T(i) {
    for(i = X + rand() % X; M[i % X] * i; i--);
        i ? M[i % X] = 2 << rand() % 2: 0;

    for(W = i = 0; i < 4; i++) {
        s(0, i);
    }


// Prints the tiles onto the terminal
    for(i = X, puts("\e[2J\e[H"); i--; i % 4 || puts("")) {
        printf(M[i] ? "%4d|":"    |", M[i]);
    }


// Read input from keyboard
    W - 2 || read(0, &k, 3) | T(s (1, K[(k >> X) % 4]));
}

int main() {

// Uses stty to clear the screen in preparation for the game
    T(system("stty cbreak"));


// Game has finished by this point

// If win, display "WIN". Otherwise, display "LOSE".
    puts(W & 1 ? "WIN" : "LOSE");
    return 0;
}

//[2048]
