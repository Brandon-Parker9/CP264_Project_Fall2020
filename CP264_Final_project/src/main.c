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
#include "BT_functions.h"

//used for testing purposes
void inorder(node *root) {
//checks is root is NULL
	if (root != NULL) {
		//Goes left until nothing is there
		inorder(root->left);
		//prints out value of node
		if (root->character != '\0') {
			printf("Character: %c Frequency: %d\n", root->character,
					root->frequency);
		} else {
			printf("Character: NULL Frequency: %d\n", root->frequency);
		}

		//then goes right
		inorder(root->right);
	}
}

int main() {

	setbuf(stdin, NULL);

	//file path of the file that we are working with
	char *file_path = "src\\message.txt";

	//creates a linked list from the the characters in the file
	linked_list *llist = file_to_array(file_path);
	node *root = (node*) malloc(sizeof(node));

	//the creates the binary tree from the linked list and returns
	//the root node of the tree
	root = create_tree_from_linked_list(llist);

	//this array will store all the strings the correspond to
	//the character location example: "101"
	char *BT_character_location[255];

	//this takes the root node and the array and adds the strings the corresponding
	//array index with the character location example: "101"
	binary_tree_to_array(root, BT_character_location);

	printf("===== Testing to show how to use array =====\n");

	//the array is indexed based on the character ascii value
	printf("\nLetter 'e' location in tree: %s\n",
			BT_character_location[((int) 'e')]);

	printf("\nLetter 'w' location in tree: %s\n",
			BT_character_location[((int) 'w')]);

	//this will prove that the values above are correct
	//I will traverse the BT based on the 1' and 0's

	printf("\nThe character located at 111 is: %c\n",
			root->right->right->right->character);

	printf("\nThe character located at 001011 is: %c\n",
			root->left->left->right->left->right->right->character);

	/* Another block of test code, not really needed
	 //prints out the data of the tree inorder
	 printf("===== Inorder ======\n");

	 inorder(root);

	 char *array[255];

	 printf("================================\n");

	 binary_tree_to_array(root, array);

	 printf("\nString: %s", array[(int) 'e']);
	 printf("\nString: %s", array[(int) ' ']);

	 */

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
