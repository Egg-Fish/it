#pragma once

#include "the/List.h"

#include <stdbool.h>
#include <stddef.h>

typedef List Stack;

Stack Stack_create(void);
void Stack_destroy(Stack s);

size_t Stack_getLength(Stack s);

void Stack_push(Stack s, void *item);
void *Stack_peek(Stack s);
void *Stack_pop(Stack s);
