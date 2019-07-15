#include <stdio.h>

#define TABSIZE 4

int main() {
    char c;
    int spaces_past_tabstop = 0;
    while ((c = getchar()) != EOF) {
        if (c == 9) {
			int spaces_til_tabstop = TABSIZE - spaces_past_tabstop;
			spaces_past_tabstop = 0;
			for (int i = 0; i < spaces_til_tabstop; i++) {
				putchar(' ');
			}
        } else if (c == '\n') {
			spaces_past_tabstop = 0;
			putchar(c);
		} else {
			spaces_past_tabstop += 1;
			putchar(c);
		}

		// reset spaces if the most recent tabstop has passed
		spaces_past_tabstop %= TABSIZE;
    }
	return 0;
}