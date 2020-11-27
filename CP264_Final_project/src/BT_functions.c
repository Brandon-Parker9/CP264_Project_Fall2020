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

void binary_tree_to_array(node *root,int val, int dir) {
	/*
	 *
	 * this function goes through the entire binary tree and creates
	 * an array of all the 0's and 1's needed for each character.
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

	if (root != NULL) {

		//goes left in the tree
		if (root->left != NULL)
			binary_tree_to_array(root->left, val<<1, 0);
		
		//	the the character at the node is not NULL, then the current value is saved
		//	for future use in the encoding
		if (root->character != '\0') {
			root->value = val;
		}

		//goes right in the tree
		if (root->right != NULL)
		{
			binary_tree_to_array(root->right, val<<1 | 1, 1);
		}
	}
	return(root, val, 0);
}