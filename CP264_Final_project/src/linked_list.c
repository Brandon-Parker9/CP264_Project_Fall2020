/*
 -------------------------------------
 File:    linked_list.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-19
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "node_struct.h"
#include "linked_list.h"

void insert_linked_list(linked_list *llist, node *node) {
	/*
	 * inserts based on node frequency. This way the linked
	 * is sorted.
	 *
	 */

	int inserted = 0;
	linked_node **curr = &(llist->start);

	//creates linked list node to be inserted
	linked_node *new_node = (linked_node*) malloc(sizeof(linked_node));
	new_node = linked_list_newNode(node);

	//linked list is empty
	if (llist->start == NULL && llist->end == NULL) {
		llist->start = llist->end = new_node;
	} else {
		while (inserted == 0) {
			//inserting at the end
			if (*curr == NULL) {
				*curr = linked_list_newNode(node);
				(*curr)->previous = llist->end;
				llist->end->next = (*curr);
				llist->end = (*curr);
				inserted = 1;
			}
			//inserted in the middle somewhere
			else if (((*curr)->node->frequency) < (node->frequency)) {
				(new_node)->next = (*curr);
				(new_node)->previous = (*curr)->previous;
				(*curr)->previous = (new_node);
				(*curr) = new_node;
				inserted = 1;
			} else

				curr = &(*curr)->next;
		}
	}

}

linked_node* linked_list_newNode(node *node) {
	/*
	 * Creates new linked list node
	 */
	linked_node *new_node = (linked_node*) malloc(sizeof(linked_node));
	new_node->next = new_node->previous = NULL;
	new_node->node = node;

	return new_node;
}
