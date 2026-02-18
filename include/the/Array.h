#pragma once

#include <stdbool.h>
#include <stddef.h>

#define ARRAY_DEFAULT_INITIAL_CAPACITY 8

typedef struct Array *Array;

Array Array_create(void);
Array Array_createFromItems(void **items, size_t length);
void Array_destroy(Array a);

size_t Array_getLength(Array a);
size_t Array_getCapacity(Array a);

void *Array_getItemAtIndex(Array a, size_t index);
void Array_setItemAtIndex(Array a, size_t index, void *item);

void Array_appendItem(Array a, void *item);

bool Array_isEmpty(Array a);
bool Array_isAtCapacity(Array a);
