/*
4. Write a program to implement double ended stack.
	class Dstack
	{
		int *arr;
		int top1, top2, size;
	};
In double ended stack addition and deletion of elements take place from both ends.
 Maintain two top indicators to perform operations.*/




#include<iostream>
#define max 8
using namespace std;


class Stack
{
	int arr[max];
	int top1,top2,size,size2;
	public:
			void push(int);
			int pop();
			void display();
			bool isEmpty();
			bool isFull() ;
			Stack();
			
};

Stack::Stack()
{
	
	size=max/2;
	size2=size;
	arr[size];
//	arr=new arr[size];
	for(int i=0;i<max;i++)
	{
		arr[i]=0;
	}
	top1= -1;
	top2=size-1;
	
}
void Stack::push(int e)
{
	int z=max,x,n;
	z--;
	cout<<"push into\t1.Stack1\t2.Stack2"<<endl;
	cin>>n;
	if(n==1)
	{
		if(top1!=size-1)
		{
			top1++;
			arr[top1]=e;
			cout<<e<<"<--- Is Pushed in Stack1"<<endl;
	
		}
		else 
		{
			
			throw x;
			isFull();
		}
	}
	else if(n==2)
	{
		if(top2!=max-1)
		{
			top2++;
			arr[top2]=e;
			cout<<e<<"<--- Is Pushed in Stack2"<<endl;
	
		}
		else 
		{
			
			throw x;
			isFull();
		}
		
	}
	
}
int Stack::pop()
{	
	int z,n;
	cout<<"push into\t1.Stack1\t2.Stack2"<<endl;
	cin>>n;
	
	if(n==1)
	{
			if(top1>=0)
			{
				cout<<arr[top1]<<"<--- Is Pooped from stack1"<<endl;
				return arr[top1--];	
				
		
			}
			else
			{
				throw z;
				isEmpty();
			}
	}
	else if(n==2)
	{
		if(top2>=size)
			{
				cout<<arr[top2]<<"<--- Is Pooped from stack2"<<endl;
				return arr[top2--];	
				
		
			}
			else
			{
				throw z;
				isEmpty();
			}
		
	}
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
	int c;
	cout<<"Display:\t1.Stack1\t2.Stack2\t3.Both"<<endl;
	cin>>c;
	if(c==1)
	{
		for(int i=top1;i>=0;i--)
			{
				cout<<"Element in stack1--- >"<<arr[i]<<endl;		
			}			
	}
	else if(c==2)
	{
		for(int i=top2;i>=size;i--)
			{
				cout<<"Element in stack2--- >"<<arr[i]<<endl;		
			}			
	}
	else
	{
		for(int i=top1;i>=0;i--)
			{
				cout<<"Element in stack1--- >"<<arr[i]<<endl;		
			}
		for(int i=top2;i>=size;i--)
			{
				cout<<"Element in stack2--- >"<<arr[i]<<endl;		
			}
		
				
	}
	
	
	
	
}	

 int main()
 {
 	int a,e,z;
 	Stack s;
 	while(1)
 	{
 	
 		cout<<"Enter the option for stack1:\n1.Push\n2.Pop\n3.Display\n0.Exit"<<endl;
 	
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
	 		//	break;
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
			//	break;
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
 
