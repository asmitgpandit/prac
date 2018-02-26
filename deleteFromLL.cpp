#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode
{
	int data;
	ListNode *next;
};

class List
{
	ListNode *head;

public:
	List() : head(NULL){}

	void append(int val)
	{
		ListNode *newNode = new ListNode;
		newNode->data = val;
		newNode->next = NULL;

		if (!head)
		{
			head = newNode;
			return;
		}

		ListNode *ptr = head;
		while(ptr->next)
			ptr = ptr->next;

		ptr->next = newNode;
	}

	void remmoveDuplicates(unordered_set<int> &uset)
	{
		ListNode *ptr = head;
		ListNode *prev = NULL;
		ListNode *next = NULL;

		if (!head)
			return;

		while(ptr)
		{
			next = ptr->next;

			if (uset.find(ptr->data) != uset.end())
			{
				//delete this node
				prev->next = next;
				delete ptr;
				ptr = next;
				continue;
			}
			else
				uset.insert(ptr->data);

			prev = ptr;
			ptr = ptr->next;
		}
	}

	void print()
	{
		ListNode *ptr = head;
		while(ptr)
		{
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		cout<<endl;
	}
};

int main()
{
	vector<int> v = {2,2,2,2,2,1,4,5,2,9,3,5,6,4,9,4,2,6,7,7,7};
	List list;
	unordered_set<int> uset;

	for(int i=0; i< v.size(); i++)
		list.append(v[i]);
	
	list.print();
	list.remmoveDuplicates(uset);
	list.print();

	return 0;
}