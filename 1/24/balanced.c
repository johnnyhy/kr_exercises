#include <stdio.h>
#include <stdlib.h>

struct stack {
    struct stack * previous;
    int val;
};

struct stack * get_frame(int c);

int main() {
    struct stack * top = NULL;
    int line = 1;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '[' || c == '{' || c == '(') {
            struct stack * temp = get_frame(c);
            temp->previous = top;
            top = temp;
        } else if (c == '\'') {
            if (getchar() == '\\') {
                getchar();
            }
            getchar();
        } else if (c == '\"') {
            int junk;
            while ((junk = getchar()) != '\"') {
                if (junk == '\\') {
                    getchar();
                }
            }
        } else if (c == '\n') {
            line += 1;
        } else if (c == ']') {
            if (top && top->val == '[') {
                struct stack * temp = top;
                top = top->previous;
                free(temp);
            } else {
                printf("unmatched closing bracket on line %d\n", line);
            }
        } else if (c == '}') {
            if (top && top->val == '{') {
                struct stack * temp = top;
                top = top->previous;
                free(temp);
            } else {
                printf("unmatched closing brace on line %d\n", line);
            }
        } else if (c == ')') {
            if (top && top->val == '(') {
                struct stack * temp = top;
                top = top->previous;
                free(temp);
            } else {
                printf("unmatched closing paren on line %d\n", line);
            }
        }
    }

    while (top) {
        struct stack * temp = top;
        top = temp->previous;
        free(temp);
    }

    return 0;
}

struct stack * get_frame(int c) {
    struct stack * top = (struct stack *) malloc(sizeof(struct stack));
    top->previous = NULL;
    top->val = c;
    return top;
}