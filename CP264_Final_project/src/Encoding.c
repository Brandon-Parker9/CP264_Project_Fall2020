/*
 -------------------------------------
 File:    Encoding.c
 Project: CP264_Final_project
 -------------------------------------
 Author:  Joshua Philip
 ID:      160673830
 Email:   phil3830@mylaurier.ca
 Version  2020-11-22
 -------------------------------------
 */

#include "Encoding.h"

void read_file_into_array(char* file_path) {
	/*
	 * reading all the file into an array that will need
	 * to be used later for the encoding
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

void find_binary_tree_encode_val(node* root, char val) {
	/*
	 *
	 * this function goes through the entire binary tree and finds
	 * the encode val to return it
	 *
	 *	How to call:
	 *		find_binary_tree_encode_val(root, char);
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

void CompressTree(unsigned int data)
{
	/*
	 * this function will take a integer value and saves it in
	 * compress.dat value
	 *
	 *	How to call:
	 *		CompressTree(data);
	 */

	FILE* file;
	char location[] = "compress.dat";
	file = fopen(location, "wb");
	fwrite(data, sizeof(unsigned int), 1, file);
	fclose(file);
	return;
}

void set_binary_tree_encode_val(node* root, int val) {
	/*
	 *
	 * this function goes through the entire binary tree and sets 
	 * the proper encode value for a all symbols in a tree.
	 *
	 *  Encode value can be found with node->value.
	 *
	 *  When calling this function, use the root node of the tree.
	 *
	 *	How to call:
	 *		binary_tree_to_array(root, 0);
	 */

	if (root != NULL) {

		//goes left in the tree if the next left is not null, saves time and is safer
		if (root->left != NULL)
			set_binary_tree_encode_val(root->left, val << 1);

		//	the the character at the node is not NULL, then the current value is saved
		//	for future use in the encoding
		if (root->character != '\0') {
			root->value = val;
		}

		//goes right in the tree if the next right is not null, saves time and is safer
		if (root->right != NULL)
		{
			set_binary_tree_encode_val(root->right, val << 1 | 1);
		}
	}
	return(root, val);
}