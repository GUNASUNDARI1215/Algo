/*

You're given a Node class that has a name and an array of optional children nodes. When put together, nodes form an acyclic tree-like structure.

Implement the depthFirstSearch method on the Mode class, which takes in an empty array, traverses the tree using the Depth-first Search approach
 (specifically navigating the tree from left to right), stores all of the nodes' names in the input array, and returns it.
 
                           A
                        /  |  \
                       B   C   D
					  / \    /  \
				    E    F  G    H
				       / \   \
				     I    J   K
					 
				Output:	  A B E F I J C D G K H     

 
 */
 
#include<iostream>
using namespace std;
 
struct Node {
	char data;
	struct Node *left;
	struct Node *right;
	struct Node *mid;
	
};

void Preorder(struct Node *root) {
	if(root == NULL) return;
	printf("%c ",root->data); 
	Preorder(root->left);     
	Preorder(root->right);    
}

struct Node* newnode(char data) 
{ 
    struct Node* node = new (struct Node); 
    node->data = data; 
    node->left = node->right  = NULL; 
    return (node); 
} 
  
 
int main()
 {

    struct Node *root = newnode('A'); 
    root->left    = newnode('B'); 
    root->right   = newnode('D'); 
    root->left->left = newnode('E'); 
    root->left->right = newnode('F'); 
    root->left->right->left = newnode('I'); 
    root->left->right->right = newnode('J'); 
    root->mid    = newnode('C'); 
    root->right->left = newnode('G'); 
    root->right->right = newnode('H'); 
    root->right->left->right = newnode('K'); 
    
	//Print Nodes in Preorder. 
	cout<<"Preorder: ";
	Preorder(root);
}
