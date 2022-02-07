// C++ program to find the left view of the given BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left,*right;
};

struct Node *newNode(int data)
{
	struct Node *node=new(struct Node);
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

void leftViewUtil(struct Node *root,int current_level,int *max_level)
{
	if (root==NULL) return;

	if(current_level > *max_level)
	{
		cout<<root->data<< " ";
		*max_level=current_level;
	}

	leftViewUtil(root->left,current_level+1,max_level);
	leftViewUtil(root->right,current_level+1,max_level);
}

void searchLeft(struct Node *root)
{
	int max_level = -1;
	leftViewUtil(root,0,&max_level);
}

int main()
{
		/*
	BINARY TREE:
				5
			  /   \
			 2     6
			/     /  \
		   4      7   9
		    \      \
		     8      8
		           /
		          10 
		         
	*/
	
	struct Node* root=newNode(5);
	root->left=newNode(2);
	root->right=newNode(6);
	root->left->left=newNode(4);
	root->left->left->right=newNode(8);
	root->right->left=newNode(7);
	root->right->left->right=newNode(8);
	root->right->left->right->left=newNode(10);
	root->right->right=newNode(9);

//leftview:
	cout<<"The left view of given BST: ";
	searchLeft(root);

	return 0;
}

