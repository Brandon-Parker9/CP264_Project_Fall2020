/*
 -------------------------------------
 File:    character_manipulation.c
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
#include <string.h>
#include "character_manipulation.h"

int frequency_array[255] = { 0 };

void string_to_array(char *string) {
	printf("String length: %ld\n", strlen(string));

	for (int i = 0; i < strlen(string); i++) {
		printf("Character: %c\n", string[i]);
		frequency_array[(int) string[i]] = frequency_array[(int) string[i]] + 1;

	}

	for (int i = 0; i < 255; i++) {
		if (frequency_array[i] != 0) {
			printf("char: %c freq: %d\n", ((char) i), frequency_array[i]);
		}

	}
}

