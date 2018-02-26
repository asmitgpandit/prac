#include <iostream>
#include <unordered_set>
#include <map>


using namespace std;
struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

class BST
{
	BSTNode *root;
	unordered_set<int> uset;


public:
	BST() : root(NULL){}

	BSTNode *getRoot() {return root;}

	void findPair(int sum, BSTNode *ptr)
	{
		if (!ptr)
			return;

		findPair(sum, ptr->left);
		if (uset.find(sum - ptr->data) != uset.end())
			cout<<"Pair is ("<<ptr->data<<","<<(sum - ptr->data)<<")"<<endl;
		uset.insert(ptr->data);
		findPair(sum, ptr->right);

	}

	void insert(int val)
	{
		BSTNode *newNode = new BSTNode;
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;

		if (!root)
		{
			root = newNode;
			return;
		}

		BSTNode *bptr = root;

		while(bptr)
		{
			if (val <= bptr->data)
			{
				if (bptr->left == NULL)
				{
					bptr->left = newNode;
					return;
				}
				bptr = bptr->left;
			
			}
			else
			{
				if (bptr->right == NULL)
				{
					bptr->right = newNode;
					return;
				}
				bptr = bptr->right;

			}
		}
	}

	void printLevelOrder(multimap<int,int> &mmap)
	{
		LevelOrderMap(0,root,mmap);

		for(auto a = mmap.begin(); a != mmap.end(); a++)
		{
			cout<<a->first<<"\t"<<a->second<<endl;
		}
	}

	void LevelOrderMap(int level, BSTNode *node, multimap<int,int> &mmap)
	{
		if(!node)
			return;

		mmap.insert(make_pair(level,node->data));
		LevelOrderMap(level+1,node->left,mmap);
		LevelOrderMap(level+1,node->right,mmap);
	}

	void printInOrder(BSTNode *ptr)
	{
		if(!ptr)
			return;

		printInOrder(ptr->left);
		cout<<ptr->data<<"\t";
		printInOrder(ptr->right);
	}

};


int main()
{

	int arr[] = {15, 10, 25, 8, 12, 20, 30, 6, 9, 18, 22, 5};
	BST BSTObj;

	for(int i=0; i< (sizeof(arr)/sizeof(int)); i++)
	{
		BSTObj.insert(arr[i]);
	}

	BSTObj.printInOrder(BSTObj.getRoot());
	BSTObj.findPair(30,BSTObj.getRoot());

	multimap<int,int> mmap;
	BSTObj.printLevelOrder(mmap);

	

	return 0;
}