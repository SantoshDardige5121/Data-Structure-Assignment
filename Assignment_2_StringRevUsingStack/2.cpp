/*2. Write a program to reverse a string using stack.*/

#include<iostream>
#include<cstring>
#include<string>
#define max 10
using namespace std;


class Stack
{
		char t[max];
	public:
			int top;
			void push(char,int);
			char pop();
			void display(int);
		//	void reverse(string);
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
void Stack::push(char e,int l)
{
	
	int	x;
	l--;
	if(l!=top)
	{
		top++;
		t[top]=e;
	}
	else 
	{
			
			throw x;
	}
}
char Stack::pop()
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
void Stack::display(int l)
{
	
	for(int i=0;i<l;i++)
	{
	
		cout<<" "<<t[top];	
			t[top]=0;
		top--;			
	}	
}

 int main()
 {
 	int a,e,z;
 	string s1;
 	Stack s;
 	
 	while(1)
 	{
 	
 		cout<<"\nEnter the option:\n1.Reverse string\n0.Exit"<<endl;
 		cin>>a;
 		
 		if(a==1)
 		{
		 		int len;
				string str;
				cout<<"Enter string"<<endl;
				cin>>str;
				len = str.length();
				int i;
				 for(i=0;i<len;i++)
				{
				 	s.push(str[i],len);		 	
		 		}
		 
		 
		 	s.display(len);	
		 }
		
		 
		 else
			{
				return 0;
		}
	}
	 return 0;
}
 
