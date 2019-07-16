/* Write a function invert(x, p, n) that returns x with the n bits
 * that begin at position p inverted, leaving the others unchanged
 */

#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int x = invert(127, 0, 5);
    printf("%d\n", x);
}

int invert(int x, int p, int n) {
    int mask = (1 << n) - 1;
    x ^= (mask << p);
    return x;
}