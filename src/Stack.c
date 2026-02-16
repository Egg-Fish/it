#include "it.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

Stack Stack_create(void) { return List_create(); }
void Stack_destroy(Stack s) { return List_destroy(s); }

size_t Stack_getLength(Stack s) { return List_getLength(s); }

void Stack_push(Stack s, void *item) { List_appendItem(s, item); }

void *Stack_peek(Stack s) { return List_getItem(s, Stack_getLength(s) - 1); }

void *Stack_pop(Stack s) {
    void *item = Stack_peek(s);

    List_removeItem(s, Stack_getLength(s) - 1);

    return item;
}
