#define MAX_QUEUE_SIZE 5
#include<iostream>

using namespace std;

class Queue
{
	int start;		//Index of first element
	int end;		//Index of the last element
	int size;		//No of elements in the queue
	int *ptr;

public:
	Queue() : start(-1), end(-1), size(0)
	{
		ptr = new int[MAX_QUEUE_SIZE];
		cout <<"Queue instantiated\n";
	}

	bool enqueue(int num);
	int dequeue();
	bool isEmpty();
	bool isFull();
};

bool Queue::enqueue(int num)
{
	if (isFull())
	{
		cout<<"ERROR : Queue is Full\n";
		return false;
	}

	if (isEmpty())
		start = 0;
	
	end++;
	end = end % MAX_QUEUE_SIZE; 	//For wrapping around
	ptr[end] = num;
	size++;
	return true;
}

int Queue::dequeue()
{
	int rv;
	if (isEmpty())
	{
		cout<<"ERROR : Queue is Empty\n";
		return -1;
	}

	rv = ptr[start];

	if (size == 1)
	{
		//This is the only element
		start = end = -1;

	}
	else
	{
		start++;
		start = start % MAX_QUEUE_SIZE; 	//For wrapping around
	}
	size--;
	return rv;
}

bool Queue::isEmpty()
{
	return (size == 0);
}

bool Queue::isFull()
{
	return (size == MAX_QUEUE_SIZE);
}

int main()
{

	Queue myQueue;

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
}