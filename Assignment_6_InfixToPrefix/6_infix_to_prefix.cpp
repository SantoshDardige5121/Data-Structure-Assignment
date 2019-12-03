#include<iostream>
#include<cstring>
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
	int i=0,j=0,x,a,b,c,l,y;
	char infix[100],postfix[100],prefix[100];
	Stack s1(100);
	char ch,temp;

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
	cout<<infix<<endl;
	l=strlen(infix);
	for(a=0;a<(l/2);a++)
	{
		temp=infix[a];
		infix[a]=infix[l-a-1];
		infix[l-a-1]=temp;
		
		
	}

	cout<<infix<<endl;
	//cout<<"answer is";
	for(a=0;a<l;a++)
	{
		if(infix[a]=='(')
		{
			infix[a]=')';
		}
		else if(infix[a]==')')
		{
			infix[a]='(';
		}		
		
	}
	cout<<infix<<endl;
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
		cout<<"Answer is postfix "<<postfix<<endl;
		l=strlen(postfix);
	for(a=0;a<l;a++)
	{
		
		prefix[a]=postfix[l-a-1];
		
	}
	postfix[a]='\0';
	
	
	cout<<"Answer is prefix   v"<<prefix<<endl;
	return 0;
}

