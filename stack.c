#include <stdio.h>

int *EOS;		//End of stack
int *SOS; 		//start of stack

void push(int **top_of_stack, int item)
{
	if (*top_of_stack == EOS)
	{
		printf("ERROR : PUSH failed ! Stack is FULL\n");
		return;
	}
	else if (!(*top_of_stack))
	{
		*top_of_stack = SOS;
		**top_of_stack = item;
	}
	else
	{
		(*top_of_stack)++;
		**top_of_stack = item;
	}

}

int pop(int **top_of_stack)
{
	int item;
	if(*top_of_stack == NULL)
	{
		printf("ERROR : POP failed ! Stack was EMPTY\n");
		return -1;
	}
	if(*top_of_stack == SOS)
	{
		item = **top_of_stack;
		(*top_of_stack) = NULL;
		return item;
	}
	else
	{
		item = **top_of_stack;
		(*top_of_stack)--;
		return item;
	}
}

int main()
{
	int stack[5];
	int *TOS = NULL;

	int stack_size = sizeof(stack)/sizeof(stack[0]);
	EOS = &stack[stack_size-1];

	SOS = stack;


	char op;
	int num;
	while(1)
	{
		printf("Which operation do you want to perform ?\n");
		scanf("%c",&op);
		while(getchar() != '\n');

		switch(op)
		{
			case '1':
			{
				printf("Enter the item : ");
				scanf("%d",&num);
				while(getchar() != '\n');
				push(&TOS,num);
				break;
			}
			case '2':
			{
				num = pop(&TOS);
				printf("The popped item is : %d\n",num);
				break;
			}
			default:
				printf("Invalid choice ! Try again\n");
				break;
		}
	}



	return 0;
}