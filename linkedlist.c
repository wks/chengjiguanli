#include <stdlib.h>

#include "linkedlist.h"

void list_init(struct ListNode *head) {
    head->next = NULL;
}

void list_insert(struct ListNode *head, struct ListNode *new_node) {
    new_node->next = head->next;
    head->next = new_node;
}

void list_delete_first(struct ListNode *head) {
    head->next = head->next->next;
}

struct ListNode* list_delete(struct ListNode *head, int index) {
    struct ListNode *rv;
    struct ListNode *before = head;

    while(index--) {
        before = before->next;
    }

    rv = before->next;
    before->next = before->next->next;

    return rv;
}

