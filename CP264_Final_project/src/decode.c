/*
 -------------------------------------
 File:    decode.c
 Project: mabi3240_Quiz3
 file description
 -------------------------------------
 Author:  William Mabia, Tobi Onabolu
 ID:      190133240
 Email:   mabi3240@mylaurier.ca
 Version  2020-09-18
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"

#include "node_struct.h"

void getFile(node *root) {
//    Have a file pointer pointing to each character in the file
//    Have a while loop to makes sure that the current._next is not NULL(Want to stop at leaf, leaf = letter)
//    For each character if its a 1 traverse right tree
//    if its a 0 traverse left
//    ** out of the loop
//    Once we hit a leaf print the leaf node.character

	char letter;
//    int , length, l = 10, j;
	FILE *readFile;

	node *curr = root;

	readFile = fopen("src\\compress.txt", "r");

	while (!feof(readFile)) {
		fscanf(readFile, "%c", &letter);
		//printf("letter: %c\n", letter);
		if (letter == '0')
			curr = curr->left;

		else if (letter == '1')
			curr = curr->right;

		if (curr->character != '\0') {
			printf("%c", curr->character);
			curr = root;
		}

		/*
		 if (letter == '0' || letter == '1') { //Prevent Infinite loop
		 while (curr->left != NULL || curr->right != NULL) {
		 if (letter == '0')
		 curr = curr->left;

		 else if (letter == '1')
		 curr = curr->right;
		 }
		 }
		 printf("%c", curr->character);
		 */
	}

	//    fgets(&letter, 50, readFile);
}

