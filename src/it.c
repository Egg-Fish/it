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

void List_destroy(List l) {
    ListNode node = l->head;

    while (node != NULL) {
        ListNode nextNode = node->next;
        free(node);
        node = nextNode;
    }

    free(l);
}

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

void List_removeItem(List l, size_t index) {
    ListNode prevNode = NULL;
    ListNode node = l->head;

    while (index > 0) {
        prevNode = node;
        node = node->next;
        index--;
    }

    ListNode nextNode = node->next;

    if (prevNode) {
        prevNode->next = nextNode;
    } else {
        l->head = nextNode;
    }

    if (nextNode == NULL) {
        l->tail = prevNode;
    }

    l->length--;
}

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
