

// list A = 1->4->5->9->NULL

// list B = 7->10->9->99->NULL

// list C = 1->7->4->10->7->10->9->99->NULL

typedef struct Node Node
struct Node
{
	int data;
	Node *next;
};




Node *Merge(Node **headA, Node **headB, Node **headC)
{

	Node *ptr = headA;

	if (headA == NULL)
		return headB;
	else if (headB == NULL)
		return headA;

	//At thispoint both list are non-empty

	//travese to the end to the first list
	while(ptr->next)
	{
		ptr = ptr->next;
	}

	ptr->next = headB;
	return headA;

}

Node *Merge(Node **headA, Node **headB, Node **headC)
{
	Node *ptrA = headA; *ptrB = headB;

	while((ptrA->next!=NULL) && (ptrB->next!=NULL))
	{
		Anext = ptrA->next;
		Bnext = ptrB->next;
		ptrA->next = ptrB;
		ptrB->next = Anext;

		ptrA = Anext;
		ptrB = Bnext;

	}

	if (ptrA->next ==NULL)
	{
		ptrA->next = Bnext;
	}
	else if (ptrB->next ==NULL)
	{
		ptrB->next = Anext;
	}
}




int main()
{
	Node *headA = NULL, *headB= NULL, *headC;

	Merge(&headA, &headB, &headC);



	return 0
}