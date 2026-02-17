#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct ListNode *ListNode;

ListNode ListNode_create(void *value, ListNode prev, ListNode next);
void ListNode_destroy(ListNode node);

void *ListNode_getValue(ListNode node);
ListNode ListNode_getPrev(ListNode node);
ListNode ListNode_getNext(ListNode node);

void ListNode_link(ListNode prev, ListNode next);
void ListNode_insert(ListNode prev, ListNode node, ListNode next);
