/*
 -------------------------------------
 File:    file_manipulation.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker, Joshua Philips
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-20
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "character_manipulation.h"
#include "file_manipulation.h"
#include "linked_list.h"

linked_list* file_to_list(char *file_path) {
	/*
	 * takes a file path as a string
	 * and converts the contents of the file to
	 * a sorted linked list based on character frequency.
	 *
	 * Parameters:
	 * 	file_path as a string - (char *)
	 *
	 * Return;
	 * 	sorted linked list (linked_list*)
	 *
	 */

	//initializes new linked list
	linked_list *llist1 = (linked_list*) malloc(sizeof(linked_list));
	llist1->end = NULL;
	llist1->start = NULL;
	FILE *file;

	//Opens file, we use rb so that our program works with non-text files
	file = fopen(file_path, "rb");

	//checks for opening correctly
	if (file == NULL) {
		printf("File not open: NULL");
	} else {
		int size;

		//determining the amount of bytes in file for the calloc then setting it back
		fseek(file, SEEK_SET, SEEK_END);
		size = ftell(file);
		fseek(file, SEEK_SET, SEEK_SET);

		//creating needed variables, use calloc as it initialize to 0
		char *contents = (char*) calloc(size + 1, sizeof(char));

		//grabbing contents of the file
		fread(contents, 1, size, file);

		//Closes file
		fclose(file);
		//Testing puposes - printf("String from file:\n\n%s\n", contents);

		//creates a linked list from string
		llist1 = string_to_array(contents);
	}
	return llist1;
}

