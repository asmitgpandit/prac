#include<iostream>

using namespace std;

class A
{
	int x;
public:
	A(int num)
	{
		x=num;
		cout <<"A's parameterised constructor"<<endl;
	}
	const int& get() const
	{
		return x;
	}
};

class B
{
	int y;
	A a;
public:
	B() : y(1), a(1)
	{
		cout <<"B's default constructor"<<endl;
	}

	void get() const
	{
		//y = 3;
		cout <<"y="<<y<<"a="<<a.get()<<endl;
	}

};

int main()
{
	const B bobj;

	bobj.get();
}