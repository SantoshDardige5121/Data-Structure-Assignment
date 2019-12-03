/*15. Implement doubly linked list with all operations mentioned in assignment 13
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next, *prev;
	
};
	
class DoublyLinkedList
{
	Node *head,*tail;
	public: 
		DoublyLinkedList();
		void addAtEnd(int);
		void addAtBegin(int);
		void addAtPos(int,int);
		void removeFromEnd();
		void removeFromBegin();
		void removeFromPos(int);
		void display();
		void rdisplay();
		//~ DoublyLinkedList();		
};
DoublyLinkedList::DoublyLinkedList()
{
	head=tail=NULL;
	
}
void DoublyLinkedList::addAtBegin(int d)
{
	Node *newnode= new Node;
	newnode->data=d;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(head==NULL && tail==NULL)
	{
		head=tail=newnode;
	
		
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
		
	}
	
	
	
}
void DoublyLinkedList::addAtEnd(int d)
{
	Node *newnode= new Node;
	newnode->data=d;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(head==NULL && tail==NULL)
	{
		head=tail=newnode;
	
		
	}
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;	
	
	}
	
	
	
}
void DoublyLinkedList::addAtPos(int d,int p)
{
	Node *cntt=head;
	int cnt=0;
	while(cntt!=NULL)
	{
		cntt=cntt->next;
		cnt++;
	}
	
	
	if(p>cnt)
	{
		cout<<"Enter correct position"<<endl;
	}
  	else {

		Node *newnode= new Node;
		newnode->data=d;
		newnode->next=NULL;
		newnode->prev=NULL;
		
		if(head==NULL && tail==NULL )
		{
			head=tail=newnode;
		
			
		}
		else if(p==1)
		{
			head->prev=newnode;
			newnode->next=head;
			head=newnode;
			
		}
		else
		{
			Node *temp;
			temp=head;
			while(p>1)
			{
				
				temp=temp->next;
			    p--;	
			}
			newnode->prev=temp->prev;
			newnode->prev->next=newnode;
			newnode->next=temp;
			temp->prev=newnode;
			
					
		}
}
	
}
void DoublyLinkedList::removeFromEnd()
{
	Node *temp=tail;
	tail=tail->prev;
	tail->next=NULL;
	delete temp;
	
}
void DoublyLinkedList::removeFromBegin()
{
	Node *temp=head;
	head=head->next;
	head->prev=NULL;
	delete temp;
}
void DoublyLinkedList::removeFromPos(int p)
{
	Node *cntt=head;
	int cnt=0;
	while(cntt!=NULL)
	{
		cntt=cntt->next;
		cnt++;
	}
	
	
	if(p>cnt)
	{
		cout<<"Enter correct position"<<endl;
	}
  	else {
  		
			if(p==1)
			{
				Node *temp=head;
				head=head->next;
				head->prev=NULL;
				delete temp;
			}
			else
			{
				Node *temp;
				temp=head;
				while(p>1)
				{
					
					temp=temp->next;
				    	p--;
				}
				if (temp->next==NULL)
				{
					Node *tempp=tail;
					tail=tail->prev;
					tail->next=NULL;
					delete tempp;	
				}
				else
				{
					temp->next->prev=temp->prev;
					temp->prev->next= temp->next;
					delete temp;
					cnt++;
				}
			}
	}
			
}
void DoublyLinkedList::display()
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" --> ";
		temp=temp->next;
		
	}
	cout<<"NULL"<<endl;
	
}
void DoublyLinkedList::rdisplay()
{
	Node *temp=tail;
	while(temp!=NULL)
	{
		cout<<temp->data<<" -*-";
		temp=temp->prev;
		
	}
		cout<<"NULL"<<endl;
	
}
int main()
{
	int ch,n,p;
	DoublyLinkedList l;
	
	while(1)
	{
		cout<<"1. Add at Begining"<<endl;
		cout<<"2. Add at End"<<endl;
		cout<<"3. Add at Postion"<<endl;
		cout<<"4. Remove from Begining"<<endl;
		cout<<"5. Remove from End"<<endl;
		cout<<"6. Remove"<<endl;
		cout<<"7. Display"<<endl;
		cout<<"8. Reverse Display"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:	cout<<"Enter element"<<endl;
					cin>>n;
					l.addAtBegin(n);			
				    break;
			case 2:	cout<<"Enter element"<<endl;
					cin>>n;
					l.addAtEnd(n);			
				    break;
			case 3:	cout<<"Enter element"<<endl;
					cin>>n;
					cout<<"Enter Postion"<<endl;
					cin>>p;
					l.addAtPos(n,p);			
				    break;
			case 4:	l.removeFromBegin();			
				    break;
			case 5:	
					l.removeFromEnd();			
				    break;
			case 6:	cout<<"Enter element Pos"<<endl;
					cin>>n;
					l.removeFromPos(n);			
				    break;
			case 7:
					l.display();
					break;
			case 8: l.rdisplay();
					break;	 
			case 0: exit(0);   
		}
		
	
	
	}	
	
	return 0;
}
