#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct List *List;

List List_create(void);
void List_destroy(List l);

size_t List_getLength(List l);

void List_appendItem(List l, void *item);

void *List_getItem(List l, size_t index);
void List_removeItem(List l, size_t index);

typedef List Stack;

Stack Stack_create(void);
void Stack_destroy(Stack s);

size_t Stack_getLength(Stack s);

void Stack_push(Stack s, void *item);
void *Stack_peek(Stack s);
void *Stack_pop(Stack s);
