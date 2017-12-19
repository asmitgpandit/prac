#include <stdlib.h>
#include <stdio.h>

typedef struct tree tree;
struct tree
{
	tree *left_child;
	int data;
	tree *right_child;
};



void insert(tree **root, int num)
{
	if(*root == NULL)
	{
		//the tree is empty
		*root = (tree *)malloc(sizeof(tree));
		(*root)->left_child = NULL;
		(*root)->right_child = NULL;
		(*root)->data = num;
	}
	else
	{
		//find the position to insert the node
		if (num < (*root)->data)
			insert(&((*root)->left_child), num);
		else
			insert(&((*root)->right_child), num);
	}
}

void print_inorder(tree *root)
{
	//printf("value of root is %d\n",(int)root);
	if (root == NULL)
		return;
	else
	{
		print_inorder(root->left_child);
		printf("%d\t",root->data);
		print_inorder(root->right_child);
	}
}

int main()
{
	tree *root = NULL;
	int arr[] = {5,2,7,88,-55,-23,2,7,10};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0; i<arr_len;i++)
	{
		insert(&root,arr[i]);
	} 
	
	print_inorder(root);
	return 0;
}