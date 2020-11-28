/*
 -------------------------------------
 File:    main.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker, Joshua Philip
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-19
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "character_manipulation.h"
#include "linked_list.h"
#include "node_struct.h"
#include "file_manipulation.h"
#include "BT_functions.h"
#include "Encoding.h"

//global for the encode search
int encode = 0;
char* contents;

//used for testing purposes
void inorder(node *root) {
//checks is root is NULL
	if (root != NULL) {
		//Goes left until nothing is there
		inorder(root->left);
		//prints out value of node
		if (root->character != '\0') {
			printf("Character: %c Frequency: %d\n", root->character,
					root->frequency);
		} else {
			printf("Character: NULL Frequency: %d\n", root->frequency);
		}

		//then goes right
		inorder(root->right);
	}
}

int main() {

	setbuf(stdin, NULL);

	char *file_path = "message.txt";
	read_file_into_array(file_path);
	linked_list *llist3 = file_to_list(file_path);
	node *root = (node*) malloc(sizeof(node));

	//linked_node *curr = llist3->start;
	root = create_tree_from_linked_list(llist3);

	//prints out the data of the tree inorder
	printf("===== Inorder ======\n");

	inorder(root);

	char *array[255];

	printf("================================\n");

	//--------------start of encoding process ------------------
	set_binary_tree_encode_val(root, 0);
	/* 
	* TODO: fix the conent saving function as there currently is
	* memory access issues.
	* TODO: save the node structure to the file as well in
	* order to be able to decode the file later.
	*/
	for (int i = 0; i < strlen(contents); i++) 
	{
		encode = 0;
		find_binary_tree_encode_val(root, contents[i]);
		printf("%x", encode);
		CompressTree(encode);
	}
	//--------------end of encoding process --------------------
	return 0;

}
