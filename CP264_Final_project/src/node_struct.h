/*
 -------------------------------------
 File:    node_struct.h
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-19
 -------------------------------------
 */
#ifndef NODE_STRUCT_H_
#define NODE_STRUCT_H_

typedef struct node {
	struct node *left;
	struct node *right;
	int frequency;
	char character;
	char *bin_vals;
} node;

node* new_node(char character, int number);
/*
 * Creates new node from character and frequency
 *
 * Parameters:
 * 	character as char
 * 	frequency of each character as int
 *
 * Returns:
 * 	returns new node (node*)
 */

#endif /* NODE_STRUCT_H_ */
