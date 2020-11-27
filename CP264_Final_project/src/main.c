/*
 -------------------------------------
 File:    main.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
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

void file_to_array(char* file_path) {
	/*
	 * takes a file path as a string
	 * and converts the contents of the file to
	 * a sorted linked list based on character frequency.
	 *
	 * Return;
	 * 	sorted linked list
	 *
	 */
	FILE* file;

	//Opens file, we use rb so that our program works with non-text files
	file = fopen(file_path, "rb");

	//checks for opening correctly
	if (file == NULL) {
		printf("File not open: NULL");
	}
	else {
		int size;

		//determining the amount of bytes in file for the calloc then setting it back
		fseek(file, SEEK_SET, SEEK_END);
		size = ftell(file);
		fseek(file, SEEK_SET, SEEK_SET);

		//creating needed variables, use calloc as it inits to 0
		contents = (char*)calloc(size + 1, sizeof(char));

		//grabbingg contents of the file
		fread(contents, 1, size, file);

		//Closes file
		fclose(file);
		printf("String from file:\n\n%s\n", contents);
	}
	return;
}

void CompressTree(unsigned int data)
{
	FILE* file;
	char location[] = "compress.dat";
	file = fopen(location, "wb");
	fwrite(data, sizeof(unsigned int), 1, file);
	fclose(file);
	return;
}

int find_binary_tree_encode_val(node* root, char val) {
	/*
	 *
	 * this function goes through the entire binary tree and finds
	 *	the encode val to return it
	 *
	 *	How to call:
	 *		val = binary_tree_find_encode_val(root, char);
	 */

	if (root != NULL && encode == 0) {

		//goes left in the tree
		if (root->left != NULL)
			find_binary_tree_encode_val(root->left, val);

		//	the the character at the node is not NULL, then the current value is saved
		//	for future use in the encoding
		if (root->character == val)
		{
			encode = root->value;
		}

		//goes right in the tree
		if (root->right != NULL)
		{
			find_binary_tree_encode_val(root->right, val);
		}
	}
}

int main() {

	setbuf(stdin, NULL);

	char *file_path = "message.txt";
	file_to_array(file_path);
	linked_list *llist3 = file_to_list(file_path);
	node *root = (node*) malloc(sizeof(node));

	//linked_node *curr = llist3->start;
	root = create_tree_from_linked_list(llist3);

	//prints out the data of the tree inorder
	printf("===== Inorder ======\n");

	inorder(root);

	char *array[255];

	printf("================================\n");

	binary_tree_to_array(root, 0, 0);

	for (int i = 0; i < strlen(contents); i++) 
	{
		encode = 0;
		find_binary_tree_encode_val(root, contents[i]);
		printf("%x", encode);
		CompressTree(encode);
	}
	return 0;

}
