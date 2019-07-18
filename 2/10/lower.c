/* Rewrite the function lower, which converts upper case letters to
 * lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

int lower(int letter);

int main() {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    int i = 0;

    while (letters[i]) {
        letters[i] = lower(letters[i]);
        i += 1;
    }

    printf("%s\n", letters);
}

int lower(int letter) {
    letter = (letter >= 65 && letter <= 90 ? letter + 32 : letter);
    return letter;
}