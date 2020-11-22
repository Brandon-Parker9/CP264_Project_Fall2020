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

typedef struct linked_node {
	struct linked_node *next;
	struct linked_node *previous;
	node *node;
} linked_node;

typedef struct linked_list {
	struct linked_node *start;
	struct linked_node *end;
	int length;
} linked_list;

void insert_linked_list(linked_list *llist, node *node);

node* create_tree_from_linked_list(linked_list *llist);

node* join_end_nodes(linked_list *llist);

linked_node* linked_list_newNode(node *node);

#endif /* LINKED_LIST_H_ */
