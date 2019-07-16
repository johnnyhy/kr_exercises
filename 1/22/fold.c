#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];

int get_line(void);

int main() {
    int len;
    int t, current_column, bookmark = 0;

    const int FOLD_LENGTH = 100;
    while ((len = get_line()) > 0) {
        if (len >= FOLD_LENGTH) {
            int t = 0;
            current_column = 0;
            while (t < len) {
                if (line[t] == ' ') {
                    bookmark = t;
                }
                if (current_column == FOLD_LENGTH) {
                    line[bookmark] =                                                                            '\n';
                    current_column = 0;
                }
                t++;
                current_column++;
            }
        }
        printf("%s", line);
    }
}

int get_line(void) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}