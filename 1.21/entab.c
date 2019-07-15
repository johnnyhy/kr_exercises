#include <stdio.h>

#define TABSIZE 4

int main() {
    char c;
    int column = 0;
    int consecutive_spaces = 0;
    int start_of_whitespace;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            consecutive_spaces += 1;
            if (!start_of_whitespace) {
                start_of_whitespace = column;
            }
            column += 1;
        } else if (c == '\n') {
            consecutive_spaces = 0;
            column = 0;
            putchar(c);
        } else {
            // once non-whitespace is reached, output combo of tabs and spaces
            for (int i = 0; i < consecutive_spaces / TABSIZE; i++) {
                putchar(9);
            }
            for (int i = 0; i < consecutive_spaces % TABSIZE; i++) {
                putchar(' ');
            }
            putchar(c);

            consecutive_spaces = 0;
            column += 1;
        }
    }
    return 0;
}