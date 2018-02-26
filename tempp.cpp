#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class account
{
     string name;
     int id;

 public:
 	account(const string n, int i) : name(n), id(i){}
 	int get_id()const {return id;}

 	// bool operator<(const account& ac) const
 	// {
 	// 	return (id > ac.id);
 	// }
};

class comp
{
public:
	bool operator()(const account& ac1, const account& ac2) const
	{
		return (ac1.get_id() > ac2.get_id());
	}
};

int main() 
{ 

	account a1 = {"asmit",20};
	account a2 = {"john",30};
	account a3 = {"at",25};
	account a4 = {"it",28};
	account a5 = {"asm",90};


	vector<account> v;

	v.push_back(a1);
	v.push_back(a2);
	v.push_back(a3);
	v.push_back(a4);
	v.push_back(a5);

	sort(v.begin(), v.end(), comp());
	for (std::vector<account>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<(*i).get_id()<<" ";
	}

  return 0; 
}