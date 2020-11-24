/*
 -------------------------------------
 File:    linked_list.h
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-19
 -------------------------------------
 */
#include "node_struct.h"

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

//double linked list node structure
typedef struct linked_node {
	struct linked_node *next;
	struct linked_node *previous;
	node *node;
} linked_node;

//structure to have start and end all in one place
typedef struct linked_list {
	struct linked_node *start;
	struct linked_node *end;
	int length;
} linked_list;

void insert_linked_list(linked_list *llist, node *node);
/*
 * inserts based on node frequency. This way the linked
 * is sorted.
 *
 * Parameters:
 * 	Takes a linked list (linked_list*) and node (node *)
 *
 */

node* create_tree_from_linked_list(linked_list *llist);
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

node* join_end_nodes(linked_list *llist);
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

linked_node* linked_list_newNode(node *node);
/*
 * Creates new linked list node
 *
 * Return:
 * 		returns new linked node (linked_node*)
 *
 */

#endif /* LINKED_LIST_H_ */
