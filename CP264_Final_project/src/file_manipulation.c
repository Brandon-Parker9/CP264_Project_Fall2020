/*
 -------------------------------------
 File:    file_manipulation.c
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
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

linked_list* file_to_array(char *file_path) {
	/*
	 * takes a file path as a string
	 * and converts the contents of the file to
	 * a sorted linked list based on character frequency.
	 *
	 * Return;
	 * 	sorted linked list
	 *
	 */

	//initializes new linked list
	linked_list *llist1 = (linked_list*) malloc(sizeof(linked_list));
	llist1->end = llist1->start = NULL;
	FILE *infile;

	//Opens file
	infile = fopen(file_path, "r");

	//checks for opening correctly
	if (infile == NULL) {
		printf("File not open: NULL");
	} else {
		char *string_from_file;
		long length;

		fseek(infile, 0, SEEK_END);
		length = ftell(infile);
		fseek(infile, 0, SEEK_SET);

		string_from_file = malloc(length);

		//gets file data
		fread(string_from_file, 1, length, infile);

		//Closes file
		fclose(infile);

		printf("String from file:\n\n%s\n", string_from_file);

		//creates a linked list from string
		llist1 = string_to_array(string_from_file);
	}
	return llist1;
}

