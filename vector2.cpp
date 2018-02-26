#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Queue
{
	stack<int> s1;
	stack<int> s2;

public:
	void enqueue(int num);
	void dequeue();
	int front();
	int back();
	int size();
};

void Queue::enqueue(int num)
{
	if (!s2.empty())
	{
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	s1.push(num);
	return;
}

void Queue::dequeue()
{
	if (s1.empty() && s2.empty())
		{	
			cout <<"Queue is already Empty\n";
			return;
		}
	else if (s1.empty())
		s2.pop();
	else 
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
}

int Queue::front()
{
	if (s1.empty() && s2.empty())
		return -1;
	else  if (s1.empty())
		return s2.top();
	else 
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}
}

int Queue::back()
{
	if (s1.empty() && s2.empty())
		return -1;
	else if (s2.empty())
		return s1.top();
	else 
	{
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return s1.top();
	}
}

int Queue::size()
{
	return s1.size() + s2.size();
}

int main()
{
	Queue q;
	
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		q.enqueue(i);
	}
	//q.dequeue();

	cout<<"Size of the Queue is : " << q.size() << endl;

	for (int i = 0; i < 5; ++i)
	{
		/* code */
		cout << q.front()<<endl;
		q.dequeue();
	}

	return 0;
}