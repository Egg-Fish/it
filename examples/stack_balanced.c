#include "it.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    Stack s = Stack_create();

    assert(Stack_getLength(s) == 0);

    const char *expr = "({}[(){[]()}])(";

    for (size_t i = 0; i < strlen(expr); i++) {
        char *item = expr + i;
        char c = *item;

        if (c == '(' || c == '[' || c == '{') {
            printf("Pushed %c.\n", c);
            Stack_push(s, item);
        } else {
            char *dptr = Stack_pop(s);
            char d = *dptr;

            if (d == '(' && c == ')') {
                printf("Matched %c and %c.\n", d, c);
            } else if (d == '[' && c == ']') {
                printf("Matched %c and %c.\n", d, c);
            } else if (d == '{' && c == '}') {
                printf("Matched %c and %c.\n", d, c);
            } else {
                printf("Did not match %c and %c.\n", d, c);
                break;
            }
        }
    }

    bool isBalanced = Stack_getLength(s) == 0;

    printf("is %s balanced? %s\n", expr, isBalanced ? "YES" : "NO");

    Stack_destroy(s);
    return 0;
}
