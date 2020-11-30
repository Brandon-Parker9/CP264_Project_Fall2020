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
#include "decode.h"
#include "global_varibles.h"

//global for the encode search
char *encode_string;
char *contents;
char *file_path = "src\\compress.txt";

int main() {

	setbuf(stdin, NULL);

	char *text_file = "src\\short.txt";

	printf("\n=============== Checking for Previous File ===============\n");

	//deletes previous file, if cannot be deleted, returns -1
	if (check_if_compress_exists() == -1)
		return -1;

	printf("\n=============== Start of Huffman Tree process ============\n");

	//-------------- Start of Huffman Tree process ------------------

	//calls the function to create sorted linked list
	linked_list *llist3 = file_to_list(text_file);

	//from the sorted linked list it creates the Huffman Tree
	// and returns the root node of the new tree

	node *root = (node*) malloc(sizeof(node));
	root = create_tree_from_linked_list(llist3);

	printf("\nTree has been created!\n");

	//-------------- End of Huffman Tree process ------------------

	printf("\n=============== Start of encoding process ================\n");

	//-------------- start of encoding process ------------------

	//sets the global variable contents to the text file contents
	read_file_into_array(text_file);

	//encodes and saves the new file
	encode_and_save(root);

	printf("\nEncoding has been completed!\n");

	//-------------- end of encoding process --------------------

	printf("\n=============== Start of decoding process ================\n\n");

	//Decodes and displays the message
	decode_display(root);

	return 0;

}
