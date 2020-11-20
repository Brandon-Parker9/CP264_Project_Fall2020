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
	linked_node *next;
	linked_node *previous;
	node *node;
} linked_node;

#endif /* LINKED_LIST_H_ */
