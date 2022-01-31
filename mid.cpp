// C++ Program to find the middle node of the linked list

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

void Print()
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		printf("->");
		temp=temp->next;
	}
	printf("NULL\n");
}

int middlenode()
{
	node* slow=head;
	node* fast=head->next;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<"The Middle Node is: "<<slow->data;		
}

int main()
{
	insert(3);
	insert(9);
	insert(99);
	insert(78);
	insert(8);
	insert(7);
	insert(89);
	insert(76);
	insert(99);
	insert(78);
	insert(84);
	//insert(27);
	
	Print();
	middlenode();
	
	return 0;
}

