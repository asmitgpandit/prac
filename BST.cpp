#include <iostream>

using namespace std;

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

class BST
{
	TreeNode *head;

public:
	BST() : head(NULL){}
	TreeNode **getHead() {return &head;}

	void insertBST(int val, TreeNode **ptr)
	{
		
		if (*ptr == NULL)
		{
			TreeNode *newNode = new TreeNode;
			newNode->value = val;
			newNode->left = NULL;
			newNode->right = NULL;
			*ptr = newNode;
			return;
		}

		if (val <= (*ptr)->value)
			insertBST(val, &((*ptr)->left));
		else 
			insertBST(val, &((*ptr)->right));
	}

	void printBST(TreeNode **ptr)
	{
		if (*ptr == NULL)
			return;

		printBST(&((*ptr)->left));
		cout<<(*ptr)->value<<" ";
		printBST(&((*ptr)->right));
	}

	int getHeight(TreeNode *ptr)
	{
		if (ptr == NULL)
			return 0;

		int leftHeight = 1 + getHeight(ptr->left);
		int rightHeight = 1 + getHeight(ptr->right);
		return max(leftHeight, rightHeight);
	}

	void LevelOrdertraversal()
	{
		for(int i=1; i<=getHeight(head); i++)
			printLevel(i, head);
	}

	void printLevel(int level, TreeNode *ptr)
	{
		if (level == 1)
		{
			cout<<ptr->value<<" ";
			return;
		}

		if (ptr->left)
			printLevel(level -1, ptr->left);
		if (ptr->right)
			printLevel(level -1, ptr->right);
	}
};


int main()
{
	BST tree;
	tree.insertBST(31,tree.getHead());
	tree.insertBST(3,tree.getHead());
	tree.insertBST(50,tree.getHead());
	tree.insertBST(6,tree.getHead());
	tree.insertBST(11,tree.getHead());
	tree.insertBST(21,tree.getHead());
	tree.printBST(tree.getHead());
	cout<<"\nHeight of the tree is : "<<tree.getHeight(*(tree.getHead()))<<endl;;
	tree.LevelOrdertraversal();
	return 0;
}