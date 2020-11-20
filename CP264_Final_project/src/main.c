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

int main() {

	//comments
	setbuf(stdin, NULL);

	char *string = "Hello and Welcome";

	printf("Hello World!\n");
	string_to_array(string);

	return 0;

}
