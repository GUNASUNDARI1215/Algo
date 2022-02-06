/*
Find Closest Value In BST

Write a function that takes in a Binary Search Tree (BST) and a target integer value and returns the closest value to that target value contained in the BST.

You can assume that there will only be one closest value.

Each BST node has an integer value, a left child node, and a right child node.
A node is said to be a valid BST node If and only if it satisfies the BST property. 
its value is strictly greater than the values of every node to its left, its value is less than or equal to the values of every node to its right; 
and its children nodes are either valid BST nodes themselves or None / null.

Sample input:
               tree =     10
                        /    \
                       5     15
					  / \   /  \
					2    5 13  22
				   /         \
				  1          14
				  
	target : 12
	
Sample output: 13

*/

#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
 

struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};


BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


BstNode* Insert(BstNode* root,int data) {
	if(root == NULL)
	{ 
		root = GetNewNode(data);
	}
	
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

BstNode* findclosestvalue(BstNode* ptr, int target, int closest)
{
	while(ptr!=NULL)
	{
		if( (abs(target - closest)) > (abs(target - ptr->data)) )
		{
			closest=ptr->data;
		}
		
		if(target < ptr->data)
		{
			ptr=ptr->left;
	    }
	    
		else if(target > ptr->data)
		{
			ptr=ptr->right;
		}
		
		else
			break;
	}
	cout<<"CLOSEST VALUE:"<<closest;
}

int main()
{
	BstNode* root = NULL;  
	root = Insert(root,10);	
	root = Insert(root,5);
	root = Insert(root,14);	
	root = Insert(root,15);
	root = Insert(root,13);
	root = Insert(root,2);
	root = Insert(root,5);
	root = Insert(root,22);
	int closest=0;
	int target;
	cout<<"Enter the target\n";
	cin>>target;
	
	findclosestvalue(root,target,closest);
}
				  
					    
