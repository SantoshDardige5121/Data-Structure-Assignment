/*
17.	Write a program to implement stack using linked list. Implement functions for below operations.
a.	 Push element
b.	Pop element
c.	Peep element
d.	Check if stack is empty

*/

#include <iostream>
using namespace std;

struct node
{
	node* next;
	int data;
};
class linkedList
{
	node* head;
	
	public : 
			linkedList();
			void addAtBegin(int);
			int removeFromBegin();
			int top();
			void display();
			
};
linkedList:: linkedList()
{
	head=NULL;
}
int linkedList::top()
{
	return head->data;	
}
void linkedList::addAtBegin(int d) 
{
	node* newnode=new node;
	newnode->data=d;
	newnode->next=head;
	head=newnode;

}
int linkedList::removeFromBegin() 
{
	int x;
	node *temp=head;
	head=head->next;
	x=temp->data;
	delete temp;
	return x;
}
void linkedList::display()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"--->";
		temp=temp->next;
		
	}
	cout<<"NULL"<<endl;
}

class stack
{	
	linkedList l;
	int top;
	public :
		  stack();
		  void push(int);
		  int pop();
		  int peep();
		  void Display();
		  
	
};
stack :: stack()
{
	top=-1;	
}

void stack::push(int d)
{
	l.addAtBegin(d);
}
int stack::pop()
{   int x;
	x=l.removeFromBegin();
	return x;
}
int stack::peep()
{
	int x=l.top();
	return x;
}
void stack::Display()
{
	l.display();
}



int main()
{
	linkedList l;
	stack s;
	
	int n,ch,d;
	
	while(1)
	{
		
		cout<<"Enter The Choice"<<endl;
		cout<<"1 -> Push"<<endl;
		cout<<"2 -> Pop"<<endl;
		cout<<"3 -> Peep"<<endl;
		cout<<"4 -> Display"<<endl;
		cout<<"5 -> Exit"<<endl;
		
		cin>>ch;
		
		switch(ch)
		{
			case 1: 
					cout<<"Enter The Data"<<endl;
					cin>>d;
					s.push(d);
					break;
			case 2: 
					cout<<s.pop()<<" <--Poped"<<endl;
					break;
			case 3: 
					cout<<s.peep()<<" <-- Top"<<endl;
					break;
			case 4: 
					s.Display();
					break;
			case 5:
				 	exit(0);
					break;
		}
		
	}
	
	
}
