/*
 -------------------------------------
 File:    character_manipulation.c
 Project: CP264_Final_project
 -------------------------------------
 Author:  Brandon Parker, Rufael Musa
 Version  2020-11-19
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character_manipulation.h"
#include "node_struct.h"
#include "linked_list.h"

linked_list* string_to_array(char *string) {
	/*
	 * creates an linked list of nodes from a string.
	 * The array is sorted by frequency from largest to smallest.
	 *
	 * Parameters:
	 *
	 * string (char *)
	 *
	 * Return:
	 * 	linked_list* - point to a linked_list
	 *
	 */

	linked_list *llist1 = (linked_list*) malloc(sizeof(linked_list));
	llist1->end = llist1->start = NULL;
	int frequency_array[130] = { 0 };

	//goes through each character in the string and updates the frequency array
	for (int i = 0; i < strlen(string); i++) {

		//character ascii value is used as index for frequency array
		frequency_array[(int) string[i]] = frequency_array[(int) string[i]] + 1;

	}

	//goes through all the items in frequency array and adds the characters with
	//a frequency greater than 0 to the sorted linked list
	for (int i = 0; i < 130; i++) {
		if (frequency_array[i] != 0) {

			insert_linked_list(llist1, new_node((char) i, frequency_array[i]));
		}
	}

	return llist1;
}

