/*
 * linkedlist.c
 * This file is part of Chengjiguanli
 *
 * Copyright (C) 2010 - Kunshan Wang
 *
 * Chengjiguanli is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Chengjiguanli is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Chengjiguanli; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */
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

