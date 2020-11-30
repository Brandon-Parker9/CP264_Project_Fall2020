/*
 -------------------------------------
 File:    decode.c
 Project: CP264 Project
 file description
 -------------------------------------
 Author:  William Mabia, Tobi Onabolu
 Version  2020-09-18
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"
#include "node_struct.h"
#include "global_varibles.h"

void decode_display(node *root) {
//    Have a file pointer pointing to each character in the file
//    Have a while loop to makes sure that the current._next is not NULL(Want to stop at leaf, leaf = letter)
//    For each character if its a 1 traverse right tree
//    if its a 0 traverse left
//    ** out of the loop
//    Once we hit a leaf print the leaf node.character

	char letter;
	char ch;
	node *curr = root;

	FILE *readFile;

	readFile = fopen(file_path, "r");

	FILE *output_file;

	output_file = fopen("src\\decoded.txt", "w");

	//go till end of the file
	while (!feof(readFile)) {
		//scan each character in the file
		fscanf(readFile, "%c", &letter);

		//goes left if the character is a 0
		if (letter == '0')
			curr = curr->left;

		//goes right if the character is a 1
		else if (letter == '1')
			curr = curr->right;

		//if character is not NULL, prints/writes out the character
		if (curr->character != '\0') {
			//outputs the character
			printf("%c", curr->character);

			//writes the character to the file
			ch = curr->character;
			fwrite(&ch, sizeof(char), 1, output_file);

			//updates curr node
			curr = root;
		}

	}

	fclose(readFile);

	fclose(output_file);

	return;
}

