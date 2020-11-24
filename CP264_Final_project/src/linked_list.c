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
	 * Parameters:
	 * 	Takes a linked list (linked_list*) and node (node *)
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
		llist->length = 1;
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
		(llist->length)++;
	}

}

node* create_tree_from_linked_list(linked_list *llist) {
	/*
	 * this function creates a BST from a sorted linked list.
	 *
	 *	Parameters:
	 *		Takes a linked list (linked_list *)
	 *
	 *  Return:
	 *  	the root of the new BST (node*)
	 *
	 */

	//goes until there is only one
	while ((llist->length) > 1) {
		// joins the two end nodes to create new node
		node *new_node = join_end_nodes(llist);

		//inserts the new_node back in to the llist base on frequency
		insert_linked_list(llist, new_node);

	}

	return llist->start->node;

}

node* join_end_nodes(linked_list *llist) {
	/*
	 *
	 * This function pops of the rear two nodes of
	 * the linked list. Then joins their data
	 * to create new node.
	 *
	 * Return:
	 *  	new node (node*)
	 *
	 */

	//gets the two end nodes
	node *new_node = (node*) malloc(sizeof(node));
	linked_node **end = &(llist->end);
	linked_node **second_from_end = &(llist->end->previous);

	//sets new node data
	new_node->frequency = (*end)->node->frequency
			+ (*second_from_end)->node->frequency;

	new_node->right = (*end)->node;
	new_node->left = (*second_from_end)->node;
	new_node->character = '\0';
	//sets the new end node for llist and updates what its next node is
	if (llist->length > 2) {
		(*second_from_end)->previous->next = NULL;
		llist->end = (*second_from_end)->previous;
	} else {
		//sets to NULL since the two nodes were the last two
		llist->start = llist->end = NULL;
	}

	//updates llist length after removing two nodes
	llist->length -= 2;

	return new_node;

}

linked_node* linked_list_newNode(node *node) {
	/*
	 * Creates new linked list node
	 *
	 * Return:
	 * 	returns new linked node (linked_node*)
	 *
	 */

	linked_node *new_node = (linked_node*) malloc(sizeof(linked_node));
	new_node->next = new_node->previous = NULL;
	new_node->node = node;

	return new_node;
}
