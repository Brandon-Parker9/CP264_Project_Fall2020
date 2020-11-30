/*
 -------------------------------------
 File:    file_manipulation.h
 Project: CP264_Final_project
 file description
 -------------------------------------
 Author:  Brandon Parker
 ID:      191593730
 Email:   park3730@mylaurier.ca
 Version  2020-11-20
 -------------------------------------
 */
#ifndef FILE_MANIPULATION_H_
#define FILE_MANIPULATION_H_

linked_list* file_to_list(char *file_path);
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

#endif /* FILE_MANIPULATION_H_ */
