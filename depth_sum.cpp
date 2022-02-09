/*
Node Depths

The distance between a node in a Binary Tree and the tree's root is called the node's depth.

Write a function that takes in a Binary Tree and returns the sum of its nodes' depths.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or Name / null.

Sample input

tree:
				1
			   / \
			  2    3
			 / \  / \
			4  5 6   7
		   / \
		  8   9
		  
Sample Output:
		depth sum = 16	 	

*/


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

int depthSum(struct Node *root,int depth)
{
	if(root==NULL)	return 0;
	
	int depth_sum=depth+depthSum(root->left,depth+1)+depthSum(root->right,depth+1);
	return depth_sum;
}

int main()
{
	struct Node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	root->left->left->left=newNode(8);
	root->left->left->right=newNode(9);
	
	int depth=0;
	cout<<"The depth Sum: "<<depthSum(root,depth);
	
	return 0;
	
}
