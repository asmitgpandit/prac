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


/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

/*
void print(Node *headA, Node *headB)
{
    Node *pA=headA, *pB=headB;
    printf("List A = [ ");
    while(pA)
    {
        printf("%d  ",pA->data);
        pA = pA->next;
    }
    printf("]\n");
    
    printf("List B = [ ");
    while(pB)
    {
        printf("%d  ",pB->data);
        pB = pB->next;
    }
    printf("]\n\n");
}

Node* MergeLists(Node *headA, Node* headB)
{
    Node *pA=headA, *pB=headB, *tempA, *tempB, *prevA=headA, *prevB=headB;
    // This is a "method-only" submission. 
    // You only need to complete this method 
    if ((headA == NULL)&&(headB == NULL))
        return NULL;
    else if ((headA == NULL)&&(headB != NULL))
        return headB;
    else if ((headA != NULL)&&(headB == NULL))
        return headA;
    
  
    while(pA)
    {
        pB = headB;
        if (!pB)
            return headA;
        //prepend to pA node
        if(pA->data > pB->data)
        {
            tempB = pB;
            headB = pB->next;
            pB->next = pA;
            
            if(pA==headA)
                headA = pB;
            else
                prevA->next = pB;
            prevA = pB;

        }
        //Append to pA node
        else if((pA->data < pB->data)&&(pA->next)&&(pA->next->data > pB->data))
        {
            tempA = pA->next;
            headB = pB->next;
            pA->next = pB;
            pB->next = tempA;
            pA = pB;
        }
        else
        {
            //printf("pA = %d\n",pA->data);
            
            //is pA poiting to the last node
            if (pA->next)
                pA = pA->next;
            else
            {
                pA->next = pB;
                headB = pB->next;
                pB->next = NULL;
            }   
             
        }
        //print(headA,headB);
      
      
  }
  return NULL;
}
*/

int main()
{
	listNode *head = NULL;
	
	head = append(head,9);
	head = append(head,5);
	head = prepend(head,10);
	head = append(head,15);
	head = prepend(head,100);
	print(head);
	
	head = reverse(head);
 	print(head);
 	head = reverseFirstn(4,head);
 	print(head);
 	
	head = delete(15,head);
	print(head);
	head = delete(3,head);
	print(head);
	head = delete(4,head);
	head = delete(1,head);
	print(head);

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

	return 0;
}