#include <iostream>
using namespace std;
#define STACK_SIZE 5


class stack
{
	int *TOS;			//Top of Stack
	int *stackPtr;		//stack pointer
public:
	stack() : TOS(NULL), stackPtr(NULL)
	{
		stackPtr = new int[STACK_SIZE];
		cout<<"Stack instantiated"<<endl;
	}
	void push(int item);
	int pop();
	bool isEmpty();
	bool isFull();
	~stack()
	{
		TOS = NULL;
		delete[] stackPtr;
	}
};

void stack::push(int item)
{
	if(isFull())
	{
		cout<<"Stack Limit reached"<<endl;
		return;
	}

	if (!TOS)
		TOS = stackPtr;
	else
		TOS++;

	*TOS = item;
}


int stack::pop()
{
	
	if (isEmpty())
	{
		cout<<"Stack is Empty"<<endl;
		return -1;
	}

	int item = *TOS;

	if (TOS == stackPtr)
		TOS = NULL;
	else
		TOS--;
	return item;
}

bool stack::isEmpty()
{
	if (!TOS)
		return true;
	else
		return false;
}

bool stack::isFull()
{
	if(TOS == (stackPtr+(STACK_SIZE-1)))
		return true;
	else
		return false;
}

int main()
{
	stack myStack;


	char op;
	int num;
	while(1)
	{
		cout<<"Which operation do you want to perform ?\n";
		cin>>op;
		//while(getchar() != '\n');

		switch(op)
		{
			case '1':
			{
				cout<<"Enter the item : ";
				cin>>num;
				//while(getchar() != '\n');
				myStack.push(num);
				break;
			}
			case '2':
			{
				num = myStack.pop();
				cout<<"The popped item is :  "<<num<<endl;
				break;
			}
			default:
				cout<<"Invalid choice ! Try again\n";
				break;
		}
	}


	return 0;
}