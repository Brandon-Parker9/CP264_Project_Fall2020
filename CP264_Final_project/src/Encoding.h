/*
 -------------------------------------
 File:    Encoding.c
 Project: CP264_Final_project
 -------------------------------------
 Author:  Joshua Philip
 ID:      160673830
 Email:   phil3830@mylaurier.ca
 Version  2020-11-22
 -------------------------------------
 */

#ifndef ENCODING_H_
#define ENCODING_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "node_struct.h"

extern int encode;
extern char* contents;
extern char decode;

void read_file_into_array(char* file_path);
void find_binary_tree_encode_val(node* root, char val);
void find_binary_tree_decode_val(node* root, char val);
int check_if_compress_exists(void);
void CompressTree(unsigned int data);
void set_binary_tree_encode_val(node* root, int val);
void read_encode_file_into_array(char* file_path);

#endif /* ENCODING_H_ */