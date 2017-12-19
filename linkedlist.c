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

int main()
{
	listNode *head = NULL;
	
	head = append(head,9);
	head = append(head,5);
	head = prepend(head,10);
	head = append(head,15);
	head = prepend(head,100);
	print(head);
/* 
	head = delete(15,head);
	print(head);
	head = delete(3,head);
	print(head);
	head = delete(4,head);
	head = delete(1,head);
	print(head);
 */
	head = deleteNode(15,head);
	print(head);
	head = deleteNode(5,head);
	print(head);
	head = deleteNode(100,head);
	print(head);
	head = deleteNode(10,head);
	print(head);

	return 0;
}