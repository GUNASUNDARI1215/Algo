// C++ program to detect the loop in a linked list

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
struct node* head;

void insert(int value)
{
	node* new_node=new node();
	new_node->data=value;
	
	if(head==NULL)
	{
		head=new_node;
	}
	
	else
	{
		new_node->next=head;
		head=new_node;
	}
}

void createLoop()
{
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
}

int detectLoop()
{
	if(head==NULL || head->next==NULL)
	{
		cout<<"Loop not found"<<endl;
		return 0;
	}
	
	node* slow=head;
	node* fast=head->next;
	
	while(slow!=fast)
	{
		if(fast==NULL || fast->next==NULL)
		{
			cout<<"Loop Not found"<<endl;	
			return 0;
		}
		slow=slow->next;
		fast=fast->next->next;
	}
	
	cout<<"Loop found"<<endl;	
	return 1;	
}

int main()
{
	insert(3);
	insert(9);
	insert(3);
	insert(8);
	insert(7);
	
	createLoop();
	detectLoop();
	
	head=NULL;
	insert(3);
	insert(9);
	insert(5);
	insert(8);
	insert(2);
	
	//createLoop();
	detectLoop();
	
	return 0;
}

