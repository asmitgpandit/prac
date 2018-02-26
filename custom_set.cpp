#include <iostream>
#include <unordered_set>
#include <list>

using namespace std;



class Block
{
	string m_name;
	list<string> m_attr;
public:
	Block(){}
	Block(string name) : m_name(name){}

	string getName() const { return m_name;}
	list<string> getAttr(){return m_attr;}

};

struct BlockHasher
{
  size_t
  operator()(const Block * pobj) const
  {
    return std::hash<std::string>()(pobj->getName());
  }
};

struct BlockComparator
{
  bool
  operator()(const Block *pobj1, const Block *pobj2) const
  {
    if (pobj1->getName() == pobj2->getName())
      return true;
    return false;
  }
};

int main()
{
	unordered_set<Block*,BlockHasher,BlockComparator> uset;
	Block obj1("a");
	Block obj2("b");
	Block obj3("c");
	Block obj4("d");
	Block obj5("e");
	
	//uset.insert(obj1);
	uset = {&obj1, &obj2, &obj3, &obj4, &obj5};
	cout<<uset.size()<<endl;

	Block *pBlkF = new Block("a");
	if(uset.find(pBlkF) != uset.end())
		cout<<"Block found"<<endl;
	else
		cout<<"Block not found"<<endl;

}