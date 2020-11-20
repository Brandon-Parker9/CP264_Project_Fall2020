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
#include "linked_list.h"
#include "node_struct.h"
#include "file_manipulation.h"

int main() {

	setbuf(stdin, NULL);

	char *file_path = "src\\message.txt";
	linked_list *llist3 = file_to_array(file_path);

	linked_node *curr = llist3->start;

	while (curr != NULL) {
		printf("char: %c freq: %d\n", curr->node->character,
				curr->node->frequency);
		curr = curr->next;
	}

	printf("\n===== End of linked List =====\n");
	printf("char: %c freq: %d\n", llist3->end->node->character,
			llist3->end->node->frequency);
	printf("char: %c freq: %d\n", llist3->end->previous->node->character,
			llist3->end->previous->node->frequency);

	/*
	 printf("=========== Strign to array testing ============\n");
	 char *string = "Hello and Welcome";
	 linked_list *llist2 = string_to_array(string);

	 linked_node *curr = llist2->start;

	 while (curr != NULL) {
	 printf("char: %c freq: %d\n", curr->node->character,
	 curr->node->frequency);
	 curr = curr->next;
	 }

	 */

	/*
	 printf("=========== Linked List Testing ============\n");

	 //testing to see if linked list insert works
	 struct node *node1 = (node*) malloc(sizeof(node));

	 struct node *node2 = (node*) malloc(sizeof(node));
	 struct node *node3 = (node*) malloc(sizeof(node));
	 struct node *node4 = (node*) malloc(sizeof(node));

	 node1->character = 'A';
	 node1->frequency = 10;

	 node2->character = 'c';
	 node2->frequency = 12;

	 node3->character = 'e';
	 node3->frequency = 20;

	 node4->character = 'Y';
	 node4->frequency = 2;

	 linked_list *llist1 = (linked_list*) malloc(sizeof(linked_list));
	 llist1->end = llist1->start = NULL;

	 insert_linked_list(llist1, node1);
	 insert_linked_list(llist1, node2);
	 insert_linked_list(llist1, node3);
	 insert_linked_list(llist1, node4);

	 linked_node *curr = llist1->start;

	 while (curr != NULL) {
	 printf("char: %c freq: %d\n", curr->node->character,
	 curr->node->frequency);
	 curr = curr->next;
	 }
	 */
	return 0;

}
