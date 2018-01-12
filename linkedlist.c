#include<stdlib.h>
#include<stdio.h>


typedef struct listNode listNode;

struct listNode 
{
	int data;
	listNode *next;
};

listNode *append(listNode *head, int num)
{
	listNode *tempNode = head;
	listNode *pNode = (listNode *)malloc(sizeof(listNode));
	pNode->data = num;
	pNode->next = NULL;

	if (head == NULL)
		head = pNode;
	else
	{
		//traverse to the last node
		while(tempNode->next)
		{	
			tempNode = tempNode->next;
		}
		tempNode->next = pNode;
	}
	return head;
}

listNode * prepend(listNode *head, int num)
{
	listNode *pNode = (listNode *)malloc(sizeof(listNode));
	pNode->data = num;
	pNode->next = head;
	head = pNode;
	return head;
}

//Delete Nth node
listNode *delete(int n, listNode *head)
{
	int i=1;
	listNode *prevNode = NULL;
	listNode *pNode = head;
	
	//traverse to the node to be deleted
	for(;(i<n)&&pNode;i++)
	{
		prevNode = pNode;
		pNode = pNode->next;
	}
	
	if (i!=n)
		printf("%dth Node doesn't exist\n",n);
	else
	{
		if (n==1)
			head = pNode->next;
		else
			prevNode->next = pNode->next;
		free(pNode);
	}
	return head;
	
}

//Delete Node with value n
listNode *deleteNode(int data, listNode *head)
{
	listNode *prevNode = NULL;
	listNode *pNode = head;
	
	//traverse to the node to be deleted
	while(pNode && pNode->data !=data)
	{
		prevNode = pNode;
		pNode= pNode->next;
	}
	if(pNode == NULL)
		printf("Node with data = %d not found\n",data);
	else
	{
		if (pNode == head)
			head = pNode->next;
		else
			prevNode->next = pNode->next;
		free(pNode);
	}
	return head;
}

listNode *reverse(listNode *head)
{
	listNode *nextNode, *prevNode = NULL, *pNode = head;
	
	while(pNode)
	{
		nextNode = pNode->next;
		pNode->next = prevNode;
		prevNode = pNode;
		pNode = nextNode;
	}
	return prevNode;
}

listNode *reverseFirstn(int n, listNode *head)
{
	listNode *prevNode=NULL, *nextNode, *pNode=head, *firstNode=head;
	
	//emptylist
	if((!head)||(n==0))
		return head;
	
	for(int i=0;(i<n)&&pNode;i++)
	{
		nextNode = pNode->next;
		pNode->next = prevNode;
		prevNode = pNode;
		pNode = nextNode;
	}
	
	firstNode->next = pNode;
	return prevNode;

}

void print(listNode *head)
{
	listNode *pNode = head;
	if (head == NULL)
		printf("The List is empty\n");
	else
	{
		printf("List = [\t");
		while(pNode)
		{
			printf("%d\t",pNode->data);
			pNode = pNode->next;
		}
		printf("]\n");
	}
}


void reverse_group(listNode **head, int start_pos, int end_pos)
{
	listNode *prev_start = NULL, *next = NULL, *curr = NULL, *prev = NULL, *prev_end = NULL, *start = *head, *end = *head, *end_next = NULL;
	int count = start_pos-1;


	//Set the start and the prev_start pointers
	while(start && (count >0))
	{	
		prev_start = start;
		start = start->next;
		count--;
	}

	//Set the end pointer
	count = end_pos-1;
	while(end && (count>0))
	{
		prev_end = end;
		end = end->next;
		count--;
	}
	end_next = end->next;

	//reverse the links in between
	curr = start->next;
	prev = start;
	while(curr!=end_next)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	//Adjust the prev_start and 
	prev_start->next = end;
	start->next = end_next;


}

int main()
{
	listNode *head = NULL;
	
	head = append(head,9);
	head = append(head,5);
	head = prepend(head,10);
	head = append(head,15);
	head = prepend(head,100);
	print(head);
	
	// head = reverse(head);
 // 	print(head);
 // 	head = reverseFirstn(4,head);
 // 	print(head);
 	
	// head = delete(15,head);
	// print(head);
	// head = delete(3,head);
	// print(head);
	// head = delete(4,head);
	// head = delete(1,head);
	// print(head);

/* 
	head = deleteNode(15,head);
	print(head);
	head = deleteNode(5,head);
	print(head);
	head = deleteNode(100,head);
	print(head);
	head = deleteNode(10,head);
	print(head);
 */

/*	
	For reverse a group
*/
	reverse_group(&head,1,4);
	print(head);

	return 0;
}