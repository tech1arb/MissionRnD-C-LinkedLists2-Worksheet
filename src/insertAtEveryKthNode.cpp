/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *head1 = head;
	if (head == NULL || K < 0)
		return NULL;
	int count = 1;
	while (head != NULL)
	{
		if (count % (K) == 0)
		{
			struct node * newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = K;
			newnode->next = head->next;
			head->next = newnode;
			head = head->next;
		}
		head = head->next;
		count++;
	}
	return head1;
}