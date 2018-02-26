#include <queue>
#include <iostream>

using namespace std;

class Stack
{
	queue<int> q1;
	queue<int> q2;
public:
	void push(int num);
	void pop();
	int top();
	int size();
};

void Stack::push(int num)
{
	if (q2.empty())
		q1.push(num);
	else 
		q2.push(num);
	return;
}

void Stack::pop()
{
	if (q1.empty() && q2.empty())
	{
		cout<<"Stack is already Empty\n";
		return;
	}
	else if (q2.empty())
	{
		while(q1.size() > 1)
		{
			q2.push(q1.front());
		}
		q1.pop();
	}
	else
	{
		while(q2.size() > 1)
		{
			q1.push(q2.front());
		}
		q2.pop();
	}
}

int Stack::top()
{
	if (q1.empty() && q2.empty())
		return -1;
	else if (q1.empty())
		return q2.back();
	else
		return q1.back();
}

int Stack::size()
{
	return q1.size() + q2.size();
}

int main()
{
	Stack s;

	std::vector<int> v = {4,2,66,9,10};

	for(auto a: v)
	{
		s.push(a);
	}

	cout<<"Size of stack : "<<s.size()<<endl;

	for (int i = 0; i < v.size(); ++i)
	{
		/* code */
		cout<<s.top();
		s.pop();
	}



	return 0;
}