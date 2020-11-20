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

//NEEDS TO BE FIXED

void insert_linked_list(linked_list *llist, node *node) {
	//inserts base on node frequency
	int inserted = 0;
	linked_node **curr = &(llist->start);

	linked_node *new_node = (linked_node*) malloc(sizeof(linked_node));
	new_node = linked_list_newNode(node);

	while (inserted == 0) {
		//linked list is empty

		if (*curr == NULL) {
			printf("1");
			*curr = linked_list_newNode(node);
			inserted = 1;
		}
		//inserting at the end
		else if ((*curr)->next == NULL) {
			printf("3");
			(new_node)->next = NULL;
			(new_node)->previous = NULL;
			(*curr)->next = (new_node);
			llist->end = (new_node);
			inserted = 1;
		}
		//inserted in the middle somewhere
		else if (((*curr)->next->node->frequency) < (node->frequency)) {
			printf("2");
			(new_node)->next = (*curr)->next;
			(new_node)->previous = (*curr);
			(*curr)->next = (new_node);
			(*curr)->next->previous = new_node;
			inserted = 1;
		}
		curr = &(*curr)->next;

	}

}

linked_node* linked_list_newNode(node *node) {
//creates new linked list node
	linked_node *new_node = (linked_node*) malloc(sizeof(linked_node));
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->node = node;

	return new_node;
}
