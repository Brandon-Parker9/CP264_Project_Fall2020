/*
 -------------------------------------
 File:    Encoding.c
 Project: CP264_Final_project
 -------------------------------------
 Author:  Joshua Philip
 Version  2020-11-22
 -------------------------------------
 */

#ifndef ENCODING_H_
#define ENCODING_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "node_struct.h"

extern char *encode_string;
extern char *contents;

void read_file_into_array(char *file_path);
void find_binary_tree_encode_val(node *root, char val);
int check_if_compress_exists(void);
void compress_tree(char *data);
void set_binary_tree_encode_val(node *root, char *string);
void read_encode_file_into_array(char *file_path);
void encode_and_save(node *root);

#endif /* ENCODING_H_ */
