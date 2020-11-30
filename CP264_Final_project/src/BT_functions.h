/*
 -------------------------------------
 File:    BST_functions.h
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 Version  2020-11-22
 -------------------------------------
 */
#ifndef BT_FUNCTIONS_H_
#define BT_FUNCTIONS_H_

#include "node_struct.h"

void binary_tree_to_array(node *root, char *array[]);
/*
 *
 * this function goes through the entire binary tree and creates
 * an array of all the 0's and 1's need for each character.
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

#endif /* BT_FUNCTIONS_H_ */
