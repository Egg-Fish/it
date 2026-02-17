#include "it.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    void *value;
    struct ListNode *prev;
    struct ListNode *next;
};

ListNode ListNode_create(void *value, ListNode prev, ListNode next) {
    ListNode node = malloc(sizeof(struct ListNode));

    node->value = value;
    node->prev = prev;
    node->next = next;

    return node;
}

void ListNode_destroy(ListNode node) { free(node); }

void *ListNode_getValue(ListNode node) { return node->value; }
void ListNode_setValue(ListNode node, void *value) { node->value = value; }

ListNode ListNode_getPrev(ListNode node) { return node->prev; }
void ListNode_setPrev(ListNode node, ListNode prev) { node->prev = prev; }

ListNode ListNode_getNext(ListNode node) { return node->next; }
void ListNode_setNext(ListNode node, ListNode next) { node->next = next; }

void ListNode_link(ListNode prev, ListNode next) {
    if (prev != NULL) {
        ListNode_setNext(prev, next);
        // prev->next = next;
    }

    if (next != NULL) {
        ListNode_setPrev(next, prev);
        // next->prev = prev;
    }
}

void ListNode_insert(ListNode prev, ListNode node, ListNode next) {
    ListNode_link(prev, node);
    ListNode_link(node, next);
}
