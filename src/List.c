#include "it.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct ListNode {
    void *value;
    struct ListNode *prev;
    struct ListNode *next;
} *ListNode;

ListNode ListNode_create(void *value, ListNode prev, ListNode next) {
    ListNode node = malloc(sizeof(struct ListNode));

    node->value = value;
    node->prev = prev;
    node->next = next;

    return node;
}

void ListNode_destroy(ListNode node) { free(node); }

void ListNode_link(ListNode prev, ListNode next) {
    if (prev != NULL) {
        prev->next = next;
    }

    if (next != NULL) {
        next->prev = prev;
    }
}

void ListNode_insert(ListNode prev, ListNode node, ListNode next) {
    ListNode_link(prev, node);
    ListNode_link(node, next);
}

ListNode ListNode_getPrev(ListNode node) { return node->prev; }
ListNode ListNode_getNext(ListNode node) { return node->next; }

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
        ListNode nextNode = ListNode_getNext(node);
        free(node);
        node = nextNode;
    }

    free(l);
}

size_t List_getLength(List l) { return l->length; }

void List_appendItem(List l, void *item) {
    size_t length = List_getLength(l);

    ListNode node = ListNode_create(item, NULL, NULL);

    ListNode_insert(l->tail, node, NULL);
    l->tail = node;

    if (length == 0) {
        l->head = node;
    }

    l->length++;
}

void *List_getItem(List l, size_t index) {
    ListNode node = l->head;

    while (index > 0) {
        node = ListNode_getNext(node);
        index--;
    }

    return node->value;
}

void List_removeItem(List l, size_t index) {
    size_t length = List_getLength(l);

    ListNode node = l->head;

    size_t i = index;
    while (i > 0) {
        node = ListNode_getNext(node);
        i--;
    }

    ListNode prevNode = ListNode_getPrev(node);
    ListNode nextNode = ListNode_getNext(node);

    ListNode_link(prevNode, nextNode);
    ListNode_destroy(node);

    if (index == 0) {
        l->head = nextNode;
    }

    if (index == length - 1) {
        l->tail = prevNode;
    }

    l->length--;
}
