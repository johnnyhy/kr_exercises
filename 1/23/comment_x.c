#include <stdio.h>

void extract_string(void);

void extract_block_comment(void);

void extract_line_comment(void);

int main() {
    int char1, char2;

    while ((char1 = getchar()) != EOF) {
        /* looks for characters representing the first part of a comment*/
        // yee yee binch try to remove me
        if (char1 == '/') {
            char2 = getchar();
            if (char2 == '*') {
                extract_block_comment();
            }
            else if (char2 == '/') {
                extract_line_comment();
            }
            else {
                putchar(char1);
                putchar(char2);
            }
        }
        else if (char1 == '\"') {
            extract_string();
        }
        else if (char1 == '\'') {
            putchar(char1);
            while ((char1 = getchar()) != '\'') {
                putchar(char1);
            }
            putchar(char1);
        }
        else {
            putchar(char1);
        }
    }
}

void extract_string(void) {
    putchar('\"');
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\"') {
            putchar('\"');
            break;
        }
        /* if escape character, place char back without evaluating */
        else if (c == '\\') {
            putchar('\\');
            putchar(getchar());
        }
        else {
            putchar(c);
        }
    }
}

void extract_block_comment(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '*') {
            if (getchar() == '/') {
                break;
            }
        }
    }
}

void extract_line_comment(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            break;
        }
    }
}