/*
 -------------------------------------
 File:    character_manipulation.h
 Project: CP264_Final_project
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-19
 -------------------------------------
 */
#ifndef CHARACTER_MANIPULATION_H_
#define CHARACTER_MANIPULATION_H_

#include "linked_list.h"

typedef struct char_item {
	char character;
	int frequency;

} char_item;

linked_list* string_to_array(char *string);
/*
 * creates an linked list of nodes from a string.
 * The array is sorted by frequency from largest to smallest.
 *
 * Parameters:
 *	Takes a string (char *)
 *
 * Return:
 * 	linked_list* - point to a linked_list
 *
 */

#endif /* CHARACTER_MANIPULATION_H_ */

