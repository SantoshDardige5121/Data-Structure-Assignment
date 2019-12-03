/*
1. Write a program to implement stack using array.
 Implement functions for below operations.
a. Push element
b. Pop element
c. Peep element
d. Check if stack is full
e. Check if stack is empty*/




#include<iostream>
#define max 5
using namespace std;


class Stack
{
	int t[max];
	public:
			int top;
			void push(int);
			void pop();
			void display();
			void peep();
			bool isEmpty();
			bool isFull() ;
			Stack();
			
};

Stack::Stack()
{
	for(int i=0;i<max;i++)
	{
		t[i]=0;
	}
	top= -1;
	
}
void Stack::push(int e)
{
	int z=max,x;
	z--;
	if(top!=max-1)
	{
		top++;
		t[top]=e;
		cout<<e<<"<--- Is Pushed"<<endl;

	}
	else 
	{
			
			throw x;
			isFull();
	}
}
void Stack::pop()
{	
	int z;
	if(top>0)
	{
		cout<<t[top]<<"<--- Is Pooped"<<endl;
		top--;	
		

	}
	else
	{
		throw z;
		isEmpty();
	}	
}
void Stack::peep()
{
	cout<<t[top]<<" <---TOP Element "<<endl;
}
bool Stack :: isEmpty()
{	int c;
		cout<<"Stack underflow"<<endl;
		return 0;

}
bool Stack :: isFull()
{
	cout<<"Stack overflow"<<endl;
		return 0;
	
}
void Stack::display()
{
	for(int i=top;i>=0;i--)
	{
		cout<<"Element --- >"<<t[i]<<endl;		
	}	
}	

 int main()
 {
 	int a,e,z;
 	Stack s;
 	while(1)
 	{
 	
 		cout<<"Enter the option:\n1.Push\n2.Pop\n3.Display\n0.Exit"<<endl;
 		cin>>a;
 		
 		if(a==1)
 		{
 			try
 			{
	 			cin>>e;
	 			cout<<"Enter the to be pushed"<<endl;

	 			s.push(e);
	 		}
	 		catch(int z)
	 		{
	 			cout<<"Stack overflow"<<endl;
	 			break;
			}
		 }
		 else if(a==2)
		 {
		 	try
		 	{
		 		cout<<"poped the element"<<endl;
	 			s.pop();
 			}
 			catch(int y)
 			{
	 			cout<<"Stack underflow"<<endl;
				break;
			}		
		 }
		 else if(a==3)
		 {
		 	cout<<"Elements in the stack"<<endl;
		 	s.display();		
		 }
		 else
			{
				return 0;
		}
	}
	 return 0;
}
 
