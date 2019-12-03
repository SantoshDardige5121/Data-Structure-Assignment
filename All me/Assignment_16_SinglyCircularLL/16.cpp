/*
8. Write a program for implementing Circular Linked List
*/

#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	
};

class Linkedlist
{
	node *head,*tail;
	public:
			Linkedlist();
			void addatbegin(int);
			void addatend(int);	
			void addatpos(int,int);
			void removefrombegin();
			void removefromend();	
			void remove(int);
			void display();
};
Linkedlist::Linkedlist()
{
	head=NULL;
	tail=NULL;
	
}
void Linkedlist::addatbegin(int d)
{
	node *newnode= new node;
	newnode->data=d;
	newnode->next=NULL;
	
	
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
	
	}
	else
	{
		
		newnode->next=head;
		tail->next=newnode;
		head=newnode;
		
    }

}
void Linkedlist::addatend(int d)
{
	node *newnode= new node;
	newnode->data=d;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
	
	}
	else
	{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
			
		/*newnode->next=head;
		tail->next=newnode;
		head=newnode;*/
		
	}
	
}

void Linkedlist::addatpos(int d, int p)
{

		node *newnode= new node;
		newnode->data=d;
		newnode->next=NULL;
		node *temp=head;
		node *follow;
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
			
		}
		else if(p==1)
		{
			newnode->next=head;
			tail->next=newnode;
			head=newnode;
		
		}
		else 
		{
		
			while(p>1)
			{
				follow=temp;
				temp=temp->next;
				
				
				p--;
			}
			follow->next=newnode;
			newnode->next=temp;
		}
	
	
}
void Linkedlist::removefrombegin()
{
	node *temp=head;
	node *te=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	
	temp->next=head->next;
	head=head->next;
	delete te;
}
void Linkedlist::removefromend()
{
	node *temp=head;
	node *follow;
	while(temp!=tail)
	{
		follow=temp;
		temp=temp->next;
		
	}
	follow->next=head;
	tail=follow;
	delete temp;
	
}
void Linkedlist::remove(int p)
{

		if(p==1)
		{
			node *temp=head;
			tail->next=head->next;
			head=head->next;
			delete temp;
		}
		else
		{
			node *temp=head;
			node *follow;
			while(p>1)
			{
				follow=temp;
				temp=temp->next;
			
				p--;
			}
			if(temp==tail)
			{
				follow->next=tail->next;
				tail=follow;
				delete temp;
			}
			else
			{
				follow->next=temp->next;
				delete temp;
			}
		
			
		}
	
		
}
void Linkedlist::display()
{
	int cnt=0;
	node *temp=head;
	while(temp!=tail)
	{
		cout<<temp->data<<"--->";
		temp=temp->next;
		cnt++;
		
	}	
	cout<<temp->data<<"--->";

	cout<<" "<<endl;	
}





int main()
{
	int ch,n,p;
	Linkedlist l;
	node *head, *prev;
	
	
	while(1)
	{
		cout<<"1. Add at Begining"<<endl;
		cout<<"2. Add at End"<<endl;
		cout<<"3. Add at Postion"<<endl;
		cout<<"4. Remove from Begining"<<endl;
		cout<<"5. Remove from End"<<endl;
		cout<<"6. Remove"<<endl;
		cout<<"7. Display"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:	cout<<"Enter element"<<endl;
					cin>>n;
					l.addatbegin(n);			
				    break;
			case 2:	cout<<"Enter element"<<endl;
					cin>>n;
					l.addatend(n);			
				    break;
			case 3:	cout<<"Enter element"<<endl;
					cin>>n;
					cout<<"Enter Postion"<<endl;
					cin>>p;
					l.addatpos(n,p);			
				    break;
			case 4:	l.removefrombegin();			
				    break;
			case 5:	
					l.removefromend();			
				    break;
			case 6:	cout<<"Enter element Pos"<<endl;
					cin>>n;
					l.remove(n);			
				    break;
			case 7:
					l.display();
					break;
			case 0:
					exit(0);					    
		}
		
	
	
	}	
	
	return 0;
}
