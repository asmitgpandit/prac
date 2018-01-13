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

class queue
{
	stack stack1;
	stack stack2;
public:
	bool enqueue(int num);
	int dequeue();
	bool isEmpty();
	bool isFull();
};

bool queue::enqueue(int num)
{
	if (isFull())
	{
		cout<<"Queue is Full\n";
		return false;
	}

	if (!stack2.isEmpty())
	{	
		while(!stack2.isEmpty())
			stack1.push(stack2.pop());
	}
	stack1.push(num);
	return true;
}

int queue::dequeue()
{
	if (isEmpty())
	{
		cout<<"Queue is Empty\n";
		return -1;
	}

	if (stack2.isEmpty())
	{
		while(!stack1.isEmpty())
			stack2.push(stack1.pop());

	}
	
	return stack2.pop();
	
}

bool queue::isEmpty()
{
	if (stack1.isEmpty() && stack2.isEmpty())
		return true;
	else
		return false;
}

bool queue::isFull()
{
	if (stack1.isFull() || stack2.isFull())
		return true;
	else
		return false;
}








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

	queue myQueue;


	char op;
	int num;
	while(1)
	{
		cout<<"Which operation do you want to perform ?\n";
		cout<<"1.Enqueue\t2.Dequeue\n";
		cin>>op;
		//while(getchar() != '\n');

		switch(op)
		{
			case '1':
			{
				cout<<"Enter the item : ";
				cin>>num;
				//while(getchar() != '\n');
				myQueue.enqueue(num);
				break;
			}
			case '2':
			{
				num = myQueue.dequeue();
				cout<<"The Dequeued item is :  "<<num<<endl;
				break;
			}
			default:
				cout<<"Invalid choice ! Try again\n";
				break;
		}
	}

	return 0;
}


