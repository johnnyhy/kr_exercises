/* Write a function rightrot(x, n) that returns the value
 * of the integer x rotated to the right by n positions.
 */

#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
    int x = rightrot(8, 1);
    printf("%d\n", x);
    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int maxbits = 8 * sizeof(unsigned int);
    n %= maxbits;
    if (n == 0) {
        return x;
    }

    unsigned int front_wrap = x << (maxbits - n);
    unsigned int back_wrap = (x >> n);
    unsigned int back_mask = (1 << (maxbits - n)) - 1; // to account for undefined right shift behavior;
    unsigned int result = front_wrap | (back_wrap & back_mask);
    return result;
}