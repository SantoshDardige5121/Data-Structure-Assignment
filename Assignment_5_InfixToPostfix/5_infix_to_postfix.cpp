#include<iostream>
using namespace std;

class Stack
{
	int size;
	int *buffer;                    
	int top;
public:
	Stack();
	Stack(int);
	void push(int);
	int pop();
	int peep();
	bool isempty();
};

bool Stack::isempty()
{
	return top==-1;
}

Stack::Stack()
{
	size=10;
	buffer=new int[size];
	top=-1;
}

Stack::Stack(int s)
{
	size=s;
	buffer=new int[size];
	top=-1;
}

void Stack::push(int ch)
{
	buffer[++top]=ch;
}

int Stack::pop()
{
	return buffer[top--];
}

int Stack::peep()
{
	return buffer[top];
}

int findprecedence(int ch)
{
	switch(ch)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
	}
}

int main()
{
	int i=0,j=0,x,a,b,c,y;
	char infix[100],postfix[100];
	Stack s1(100);
	char ch;

	cout<<"Enter fully parathesized infix expression"<<endl;
	cin>>infix;
	
	while(infix[i++]!='\0');
	infix[i+1]='\0';
	infix[i--]=')';
	while(i>0)
	{
		infix[i]=infix[i-1];
		i--;
	}
	infix[i]='(';
	
	//cout<<infix<<endl;
	i=0;
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		{
			s1.push(infix[i]);
		}
		else if(infix[i]>='a' && infix[i]<='z')
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
		{
			while(s1.peep()=='+'||s1.peep()=='-'||s1.peep()=='*'||s1.peep()=='/')
			{
				if(findprecedence(s1.peep())>=findprecedence(infix[i]))
				{
					postfix[j++]=s1.pop();
				}
				else
					break;
			}
			s1.push(infix[i]);
			
		}
		else if(infix[i]==')')
		{
			while((ch=s1.pop())!='(')
			{
				postfix[j++]=ch;
			}
		}
		
		i++;
		
	}
	postfix[j]='\0';
	
	
	
	cout<<"Answer is "<<postfix<<endl;
	return 0;
}

