#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct ListNode {
    struct ListNode *next;
};

void list_init(struct ListNode *head);
void list_insert(struct ListNode *head, struct ListNode *new_node);
void list_delete_first(struct ListNode *head);
struct ListNode* list_delete(struct ListNode *head, int index);

#define list_for_each(var, head) for((var)=(head)->next; (var)!=NULL; (var)=(var)->next)

#endif
