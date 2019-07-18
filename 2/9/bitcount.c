/* In a two's complement number system, x &= (x - 1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version
 * of bitcount.
 *
 * Explanation: Take the example 10000b. Subtraction by 1 gives us 01111b.
 *              The &= of these two numbers is 0, removing the rightmost
 *              bit in x. Subtraction by one will always set the rightmost
 *              bit to 0, and all lower-order bits to 1. None of the training
 *              bits of x and x-1 overlap, which means that their &= eliminates
 *              the rightmost bit in all cases.
 */

#include <stdio.h>

int bitcount(unsigned int x);

int main() {
    for (int i = 0; i < 20; i++) {
        printf("bits in %d: %d\n", i, bitcount(i));
    }
    return 0;
}

int bitcount(unsigned int x) {
    int bits = 0;

    // iteratively slices off the last 1-bit while keeping a counter
    while (x) {
        bits += 1;
        x &= (x - 1);
    }

    return bits;
}