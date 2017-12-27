#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node 
{
	int data;
	Node *prev;
	Node *next;
};

void append(int data, Node **head)
{
	Node *pNode = *head;
	Node *prev = NULL;
	
	Node *ptr = (Node *)malloc(sizeof(Node));
	ptr->data = data;
	
	if (pNode)
	{
		//traverse to the last node
		while(pNode->next)
		{
			prev = pNode;
			pNode = pNode->next;
		}
		
		pNode->next = ptr;
		pNode->prev = prev;
	}
	else
	{
		//List id empty
		*head = ptr;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}

}

void prepend(int data, Node **head)
{
	Node *ptr = (Node *)malloc(sizeof(Node));
	ptr->data = data;
	ptr->next = *head;
	(*head)->prev = ptr;
	*head = ptr;
}

void print (Node **head)
{
	Node *pNode = *head;
	
	printf("List = [");
	while(pNode)
	{
		printf("  %d  ",pNode->data);
		pNode = pNode->next;
	}
	printf("]\n");

}
int main()
{
	Node *head = NULL;
	
	append(6,&head);
  	prepend(10,&head);
  	print(&head);
// 	delete(4,&head);
// 	swapWithNext(3,&head);
// 	swapWithPrev(2,&head);

	return 0;
}