#include "it.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct ListNode {
    void *value;
    struct ListNode *next;
} *ListNode;

struct List {
    size_t length;
    ListNode head;
    ListNode tail;
};

List List_create(void) {
    List l = malloc(sizeof(struct List));

    l->length = 0;
    l->head = NULL;
    l->tail = NULL;

    return l;
}

void List_destroy(List l) { free(l); }

size_t List_getLength(List l) { return l->length; }

void List_appendItem(List l, void *item) {
    ListNode node = malloc(sizeof(struct ListNode));
    node->value = item;
    node->next = NULL;

    if (l->head == NULL) {
        l->tail = node;
        l->head = node;
    } else {
        l->tail->next = node;
        l->tail = node;
    }

    l->length++;
}

void *List_getItem(List l, size_t index) {
    ListNode node = l->head;

    while (index > 0) {
        node = node->next;
        index--;
    }

    return node->value;
}
