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
		int count = 0;
		struct node *temp = head;
		while (temp)
		{
			temp = temp->next;
			count++;
		}
		if (K > count || K <= 0)
			return head;
		if (head == NULL)
			return NULL;
		temp = head;
		while (temp)
		{
			count = K - 1;
			while (count > 0 && temp)
			{
				temp = temp->next;
				count--;
			}
			if (temp)
			{
				struct node *tempinsert = (struct node *)malloc(sizeof(struct node));
				tempinsert->num = K;
				tempinsert->next = temp->next;
				temp->next = tempinsert;
				temp = tempinsert->next;
			}
		}
		return head;
	}
