/* Write a function setbits(x, p, n, y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y,
 * leaving the other bits unchanged.
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x = setbits(0, 3, 4, 127);
    printf("%d\n", x);
    return 0;
}

int setbits(int x, int p, int n, int y) {
    int mask = (1 << n) - 1;
    y = (y & mask) << p;
    x = x & ~(mask << p);
    x = x | y;
    return x;
}