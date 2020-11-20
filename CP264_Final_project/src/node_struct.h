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
} node;

node* new_node(char character, int number);

#endif /* NODE_STRUCT_H_ */
