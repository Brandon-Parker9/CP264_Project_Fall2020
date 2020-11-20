/*
 -------------------------------------
 File:    character_manipulation.h
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-19
 -------------------------------------
 */
#ifndef CHARACTER_MANIPULATION_H_
#define CHARACTER_MANIPULATION_H_

typedef struct char_item {
	char character;
	int frequency;

} char_item;

void string_to_array(char *string);

#endif /* CHARACTER_MANIPULATION_H_ */
