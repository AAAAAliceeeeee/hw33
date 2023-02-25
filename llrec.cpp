#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if (head == NULL)
	{
		smaller = NULL;
		larger = NULL;
		return;
	}

	Node** temp = &head; 
	
	if (head->val <= pivot)
	{
		smaller = head;
		Node* nextn = head->next;
		llpivot(nextn, smaller->next, larger, pivot);
	}
	else
	{
		larger = head; 
		Node* nextn = head->next;
		llpivot(nextn, smaller, larger->next, pivot);
	}
	*temp = NULL; 
}
