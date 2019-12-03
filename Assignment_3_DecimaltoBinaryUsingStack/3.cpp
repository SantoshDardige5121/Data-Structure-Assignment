/*3. Write a program to convert a 
decimal number into its binary form using stack.*/

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
			void d2b();
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
	if(z!=top)
	{
		top++;
		t[top]=e;
	}
	else 
	{
			
			throw x;
	}
}
void Stack::pop()
{	
	int z;
	if(top!=0)
	{
		t[top]=0;
		top--;	
	}
	else
	{
		throw z;
	}	
}
void Stack::display()
{
	for(int i=0;i<=top;i++)
	{
		cout<<"Element ---"<<t[i]<<endl;		
	}	
}
void Stack::d2b()
{
	for(int i=top;i>=0;i--)
	{
		cout<<"Element ---"<<t[top]<<endl;
		t[top]=0;
		top--;	
	}	
}	

 int main()
 {
 	int a,e,z;
 	Stack s;
 	while(1)
 	{
 	
 		cout<<"Enter the option:\n1.Push\n2.Pop\n3.Decimal to Binary\n4.Display\n0.Exit"<<endl;
 		cin>>a;
 		
 		if(a==1)
 		{
 			try
 			{
	 			cout<<"Enter the to be pushed"<<endl;
	 			cin>>e;
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
		 	int r,q;
		 	cout<<"Elements Decimal To Binary"<<endl;
		 	cin>>z;
		 	while(z!=0)
		 	{
		 		s.push(z%2);
		 		z=z/2;	 		
		 		
			 } 	
		 	
		 	
		 	s.d2b();		
		 }
		else if(a==4)
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
 
