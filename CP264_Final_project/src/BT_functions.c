/*
 -------------------------------------
 File:    BST_functions.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-22
 -------------------------------------
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "node_struct.h"
#include "linked_list.h"

void search_binary_tree(node *root, char character, int *left, int *right,
		char **string) {
	if (root != NULL) {
		//Goes left until nothing is there
		(*left)++;
		strcat(*string, "L");

		search_binary_tree(root->left, character, left, right, string);
		(*left)--;
		(*string)[strlen((*string)) - 1] = 0;

		if (root->character != '\0') {
			printf("Character: %c Right: %d Left: %d String: %s\n",
					root->character, *right, *left, *string);
		}
		(*right)++;
		strcat(*string, "r");

		search_binary_tree(root->right, character, left, right, string);

		(*right)--;
		(*string)[strlen((*string)) - 1] = 0;

	}
}
