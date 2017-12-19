#include <iostream>

using namespace std;
class B
{
public:
	int b;
	B(){}
	B(int num)
	{
		cout << "B's parameterised constructor" <<endl;
		b=num;
	}
};
class complex
{
	int real;
	int imag;
	B obj;
	
public:
	complex(): real(1),imag(1), obj(0)
	{
		cout<<"default-constructor"<<endl;
	}
	complex(int real_no, int imag_no): real(real_no), imag(imag_no)
	{

		cout<<"parameterized constructor"<<endl;
	}
	//~complex(){cout<<"destructor"<<endl;}
	void show() const
	{
		cout << "Complex Number = " <<real<<"+i"<<imag<<" and obj = "<<obj.b<<endl;
	}
	complex operator+(complex & b)
	{
		complex c;
		c.real = this->real + b.real;
		c.imag = this->imag + b.imag;
		c.obj = this->obj.b + b.obj.b;
		return c;
	}
	

};









int main()
{
	complex a(3,4), b,c;
	c.show();
	c = a;
	(b+a).show();
	return 0;
}