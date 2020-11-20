/*
 -------------------------------------
 File:    node_struct.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-20
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "node_struct.h"

node* new_node(char character, int frequency) {
	/*
	 * Creates new node from character and frequency
	 */

	node *new_node = (node*) malloc(sizeof(node));
	new_node->left = new_node->right = NULL;
	new_node->frequency = frequency;
	new_node->character = character;

	return new_node;
}
