/*
Branch Sums

Write a function that takes in a Binary Tree and returns a list of its branch sums ordered from leftmost branch sum to rightmost branch sum.

A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree branch is a path of nodes in a tree that starts at the root node 
and ends at any leaf node.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or None / null.


                           1 
                        /    \
                       2      3
					  / \    /  \
				    4    5  6    7
				  /  \  / 
				8     9 10     

branch sums: 15,16,18,10,11 
*/

#include<iostream>
#include<vector>
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


BstNode* braSum(BstNode* root, int sum, vector<int> &ans)
{
    if(root==NULL)
		return 0; 
    sum += root->data;
    if(root->left==NULL && root->right==NULL)
	{
        ans.push_back(sum);
        return 0;
    }
    braSum(root->left,sum,ans);
    braSum(root->right,sum,ans);
}

int main()
{  
	BstNode* root = GetNewNode(1); 
    
    root->left = GetNewNode(2);                  
    root->right = GetNewNode(3); 
    root->left->left = GetNewNode(4);
    root->left->right = GetNewNode(5);
    root->right->left = GetNewNode(6);
    root->right->right =GetNewNode(7);
    root->left->left->left = GetNewNode(8);
    root->left->left->right = GetNewNode(9);
    root->left->right->right = GetNewNode(10);
    
    vector<int> ans;
    cout<<"Branch Sums: ";
    braSum(root,0,ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
