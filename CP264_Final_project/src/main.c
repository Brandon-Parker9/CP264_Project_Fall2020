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

void inorder(node *root) {
//checks is root is NULL
	if (root != NULL) {
		//Goes left until nothing is there
		inorder(root->left);
		//prints out value of node
		printf("Character: %c Frequency: %d\n", root->character,
				root->frequency);
		//then goes right
		inorder(root->right);
	}
}

int main() {

	setbuf(stdin, NULL);

	char *file_path = "src\\message.txt";
	linked_list *llist3 = file_to_array(file_path);
	node *root = (node*) malloc(sizeof(node));

	linked_node *curr = llist3->start;
	root = create_tree_from_linked_list(llist3);

	/*test to make sure the new BST was generate properly

	 //prints of the contents of linked list
	 while (curr != NULL) {
	 printf("char: %c freq: %d\n", curr->node->character,
	 curr->node->frequency);
	 curr = curr->next;
	 }
	 //checks to see if two end nodes are correct
	 printf("\n===== End of linked List =====\n");
	 printf("char: %c freq: %d\n", llist3->end->node->character,
	 llist3->end->node->frequency);
	 printf("char: %c freq: %d\n", llist3->end->previous->node->character,
	 llist3->end->previous->node->frequency);
	 printf("==================================\n");
	 //creates the new BST
	 root = create_tree_from_linked_list(llist3);
	 curr = llist3->start;

	 //checks to see how many elements are in thee linked list after BST creation(should only be 1)
	 while (curr != NULL) {
	 printf("char: %c freq: %d\n", curr->node->character,
	 curr->node->frequency);
	 curr = curr->next;
	 }

	 //prints out the data of the tree inorder
	 printf("===== Inorder ======\n");

	 inorder(root);
	 */
	/*
	 printf("\n===== End of linked List After join_end_nodes =====\n");
	 printf("char: %c freq: %d\n", llist3->end->node->character,
	 llist3->end->node->frequency);
	 printf("char: %c freq: %d\n", llist3->end->previous->node->character,
	 llist3->end->previous->node->frequency);

	 curr = llist3->start;

	 while (curr != NULL) {
	 printf("char: %c freq: %d\n", curr->node->character,
	 curr->node->frequency);
	 curr = curr->next;
	 }
	 */
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
