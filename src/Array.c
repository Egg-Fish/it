#include "it.h"

#include <stdbool.h>
#include <stddef.h>

struct Array {
    size_t length;
    size_t capacity;
    void **items;
};

Array Array_create(void) {
    Array a = malloc(sizeof(struct Array));

    size_t length = 0;
    size_t capacity = ARRAY_DEFAULT_INITIAL_CAPACITY;
    void **items = calloc(capacity, sizeof(void *));

    a->length = length;
    a->capacity = capacity;
    a->items = items;

    return a;
}

Array Array_createFromItems(void **items, size_t length) {
    Array a = malloc(sizeof(struct Array));

    size_t capacity = length > 0 ? length * 2 : ARRAY_DEFAULT_INITIAL_CAPACITY;

    a->length = length;
    a->capacity = capacity;
    a->items = calloc(capacity, sizeof(void *));

    for (size_t i = 0; i < length; i++) {
        a->items[i] = items[i];
    }

    return a;
}

void Array_destroy(Array a) {
    free(a->items);
    free(a);
}

void **Array_getItems(Array a) { return a->items; }

size_t Array_getLength(Array a) { return a->length; }
void Array_setLength(Array a, size_t length) { a->length = length; }
void Array_incrementLength(Array a) {
    size_t length = Array_getLength(a);
    Array_setLength(a, length + 1);
}
void Array_decrementLength(Array a) {
    size_t length = Array_getLength(a);
    Array_setLength(a, length - 1);
}

size_t Array_getCapacity(Array a) { return a->capacity; }
void Array_setCapacity(Array a, size_t capacity) {
    a->capacity = capacity;
    a->items = realloc(a->items, capacity * sizeof(void *));
}
void Array_doubleCapacity(Array a) {
    size_t capacity = Array_getCapacity(a);
    Array_setCapacity(a, capacity * 2);
}

void *Array_getItemAtIndex(Array a, size_t index) { return a->items[index]; }
void Array_setItemAtIndex(Array a, size_t index, void *item) { a->items[index] = item; }

void Array_appendItem(Array a, void *item) {
    if (Array_isAtCapacity(a)) {
        Array_doubleCapacity(a);
    }

    size_t length = Array_getLength(a);

    Array_setItemAtIndex(a, length, item);
    Array_incrementLength(a);
}

bool Array_isEmpty(Array a) { return Array_getLength(a) == 0; }
bool Array_isAtCapacity(Array a) { return Array_getLength(a) == Array_getCapacity(a); }
