#include "it.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

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
void List_setLength(List l, size_t length) { l->length = length; }
void List_incrementLength(List l) { l->length++; }
void List_decrementLength(List l) { l->length--; }

ListNode List_getHead(List l) { return l->head; }
void List_setHead(List l, ListNode head) { l->head = head; }

ListNode List_getTail(List l) { return l->tail; }
void List_setTail(List l, ListNode tail) { l->tail = tail; }

void *List_getItem(List l, size_t index) {
    ListNode node = List_getHead(l);

    while (index > 0) {
        node = ListNode_getNext(node);
        index--;
    }

    return ListNode_getValue(node);
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
        List_setHead(l, nextNode);
    }

    if (index == length - 1) {
        List_setTail(l, prevNode);
    }

    List_decrementLength(l);
}

void List_appendItem(List l, void *item) {
    ListNode node = ListNode_create(item, NULL, NULL);

    ListNode_insert(List_getTail(l), node, NULL);
    List_setTail(l, node);

    if (List_isEmpty(l)) {
        List_setHead(l, node);
    }

    List_incrementLength(l);
}

bool List_isEmpty(List l) { return List_getLength(l) == 0; }
