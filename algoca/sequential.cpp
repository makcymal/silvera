#include <bits/stdc++.h>

using namespace std;

int f(int x);

void floyd_cycle(int x) {
    int tort = f(x), hare = f(f(x)), len = 1, pos = 0;
    while (tort != hare) {
        tort = f(tort);
        hare = f(f(hare));
    }
    tort = x;
    while (tort != hare) {
        tort = f(tort);
        hare = f(hare);
        pos++;
    }
    hare = f(hare);
    while (tort != hare) {
        hare = f(hare);
        len++;
    }
}

void brent_cycle(int x) {
    int tort = x, hare = f(x), pow = 1, len = 1, pos = 0;
    while (tort != hare) {
        if (pow == len) {
            pow *= 2;
            len = 0;
            tort = hare;
        }
        hare = f(hare);
        len++;
    }
    tort = hare = x;
    for (int i = 0; i < len; ++i) hare = f(hare);
    while (tort != hare) {
        tort = f(tort);
        hare = f(hare);
        pos++;
    }
}
