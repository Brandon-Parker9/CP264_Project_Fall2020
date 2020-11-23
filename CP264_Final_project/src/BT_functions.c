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

void binary_tree_to_array(node *root, char character, char **string,
		char *array[]) {
	if (root != NULL) {
		//Goes left until nothing is there
		strcat(*string, "L");

		binary_tree_to_array(root->left, character, string, array);
		(*string)[strlen((*string)) - 1] = 0;

		if (root->character != '\0') {
			printf("Character: %c String: %s\n", root->character, *string);
			array[(int) root->character] = *string;
		}

		strcat(*string, "r");

		binary_tree_to_array(root->right, character, string, array);

		(*string)[strlen((*string)) - 1] = 0;

	}
}
