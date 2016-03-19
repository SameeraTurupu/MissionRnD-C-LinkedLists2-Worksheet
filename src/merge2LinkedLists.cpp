/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
		if (!head1)
			return head2;
		if (!head2)
			return head1;
		struct node *head;
		if (head1->num < head2->num)
		{
			head = head1;
		}
		else
		{
			head = head2;
			head2 = head1;
			head1 = head;
		}
		while (head1->next && head2)
		{
			if (head1->next->num > head2->num)
			{
				struct node *tmp = head1->next;
				head1->next = head2;
				head2 = tmp;
			}
			head1 = head1->next;
		}
		if (!head1->next)
			head1->next = head2;
		return head;
}
