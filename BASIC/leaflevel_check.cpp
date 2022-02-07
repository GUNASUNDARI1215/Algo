// C++ Program to check whether the leaf nodes are at same level 

#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 

struct Node* newNode(int data) 
{ 
   struct Node *node=new(struct Node);
    node->data=data; 
    node->left=node->right=NULL; 
    return node; 
} 

bool check_same(struct Node *root, int current_level, int *first_leafLevel) 
{  
    if(root == NULL) return true; 
  
    if(root->left==NULL &&  root->right==NULL) 
    { 
        if(*first_leafLevel==0) 
        { 
            *first_leafLevel=current_level;
            return true; 
        } 

        return(current_level==*first_leafLevel); 
    } 
    
    return check_same(root->left,current_level+1,first_leafLevel) && check_same(root->right,current_level+1,first_leafLevel); 
} 

bool check(struct Node *root) 
{ 
    int current_level=0, first_leafLevel=0; 
    return check_same(root,current_level,&first_leafLevel); 
} 
  
int main() 
{ 
	/*
  				 19
      	 	    /    
     		   5             
  	 	      /  \          
  			 6    9
 		    /    /
	       1    2
	       
	*/
  
   
    struct Node *root=newNode(19); 
    root->left=newNode(5); 
    root->left->left=newNode(6); 
    root->left->right=newNode(9); 
    root->left->left->left=newNode(1); 
    root->left->right->left=newNode(2); 
    
    if (check(root)) 
    	cout <<"Leaves are at same level"; 
    else
        cout <<"Leaves are not at same level"; 
   
    return 0; 
} 
  
