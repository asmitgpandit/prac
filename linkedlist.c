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

listNode *interleave(listNode **head1, listNode **head2)
{
	listNode *pNode1 = *head1, *pNode2 = *head2;
	listNode *p1next, *p2next;

	if (!pNode1)
		return pNode2;
	else
		return pNode1;
	
	while(pNode1->next && pNode2->next) 
	{
		p1next = pNode1->next;
		p2next = pNode2->next;
		pNode1->next = pNode2;
		pNode2->next = p1next;
		pNode1 = p1next;
		pNode2 = p2next;
	}
	if(!pNode1->next)
		pNode1->next = pNode2;

	if(!pNode2->next)
	{
		p1next = pNode1->next;
		pNode1->next = pNode2;
		pNode2->next = p1next;
	}
	return *head1;
}

listNode* deleteDuplicates(listNode* head) 
{
    listNode *next, *pNode = head;
    
    while(pNode->next)
    {
        next = pNode->next;
        if(pNode->data == next->data)
        {
            pNode->next = next->next;
            free(next);
        }
        else
        	pNode = pNode->next;
    }
    return head;
}

listNode* reverseBetween(listNode* head, int m, int n) 
{
    listNode *pNode = head, *firstPrev, *lastNext, *prev=NULL, *next, *first, *last;
    int count=0;
    
    while(pNode)
    {
        count++;
        next = pNode->next;
        
        if(m == n)
        	return head;

        if(count == m)
        {
            first = pNode;
            firstPrev = prev;
        }
        if (count == n)
        {
            last = pNode;
            lastNext = pNode->next;
        }
        if ((count>m)&&(count<=n))
        {
            pNode->next = prev;
        }
        
        prev = pNode;
        pNode = next;
    }
    if(firstPrev)
    	firstPrev->next = last;
    else
    	head = last;
    first->next = lastNext;
    
    return head;
}

listNode* wipeDuplicates2(listNode* head) 
{
    listNode *pNode=head, *prev=NULL, *next; 
    
    if(!pNode)
        return NULL;
    
    while(pNode && pNode->next)
    {
        next = pNode->next;
        
        if(pNode->data == next->data)
        {
            while(pNode->data == next->data)
            {
                pNode->next = next->next;
                free(next);
                next = pNode->next;
            }
            //delete self
            if(prev)
                prev->next = next;
            else
                head = next;
            free(pNode);
            pNode = next;
        }
        else
        {
	        prev = pNode;
	        pNode = next;
        }
    }
    return head;
}

int main()
{
	listNode *head = NULL;
	
	//head = append(head,2);
	head = append(head,5);
	head = append(head,5);
	head = append(head,5);
	head = append(head,10);
	head = append(head,15);
	head = append(head,15);
	head = append(head,100);
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

	reverse_group(&head,1,4);
	print(head);
*/
/*	
	head = reverseBetween(head,1,4);
	print(head);
*/
/* for Interleave
	listNode *head2 = NULL;
	head2 = append(head2,19);
	head2 = append(head2,50);
	head2 = prepend(head2,120);
	head2 = append(head2,1);
	head2 = prepend(head2,102);
	head2 = append(head2,13);
	head2 = append(head2,55);
	print(head2);

	head2 = interleave(&head, &head2);
	print(head2);
*/
/* for deleteDuplicates()	
	deleteDuplicates(head);
	print(head);
*/
/*
	head = wipeDuplicates2(head);
	print(head);
*/
	return 0;
}