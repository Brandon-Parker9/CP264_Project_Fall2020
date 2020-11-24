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

void binary_tree_to_array(node *root, char *array[]) {
	/*
	 *
	 *  this function goes through the entire binary tree and creates
	 *  an array of all the 0's and 1's need for each character.
	 *  example - "001" left, left, right
	 *
	 *  The array then can be indexed based on the character ascii value.
	 *
	 *  When calling this function, use the root node of the tree.
	 *
	 *  Parameters:
	 *
	 *  	Also, use an array of like this - char *array[255];
	 *
	 *	How to call:
	 *		binary_tree_to_array(root, array);
	 */

	//string to keep track of all the 0's and 1's, i thought a size of 100 should be enough
	//realistically probably 50 would do or even less
	static char string1[100];

	if (root != NULL) {

		//adds a 0 before going left
		strcat(string1, "0");

		//goes left in the tree
		binary_tree_to_array(root->left, array);

		//removes the last character by setting it to NULL
		(string1)[strlen((string1)) - 1] = 0;

		//the the character at the node is not NULL, then the 0's and 1's
		//are added to the array based on the character ascii value.
		if (root->character != '\0') {
			// this is was for testing purposes - printf("Character: %c String: %s\n", root->character, string1);
			array[((int) root->character)] = malloc(strlen(string1) + 1);
			strcpy(array[((int) root->character)], string1);
		}

		//adds a 1 before going left
		strcat(string1, "1");

		//goes right in the tree
		binary_tree_to_array(root->right, array);

		//removes the last character by setting it to NULL
		(string1)[strlen((string1)) - 1] = 0;

	}
}
