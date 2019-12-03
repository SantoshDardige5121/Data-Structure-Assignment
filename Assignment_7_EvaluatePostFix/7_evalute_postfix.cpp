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
	int i=0,j=0,ch,x,a,b,c,y;
	char input[100],output[100];
	Stack s1(100);

	cout<<"Enter fully parathesized infix expression"<<endl;
	cin>>input;
	while(input[i]!='\0')
	{
		if(input[i]>='0' &&input[i]<='9')
		{
			x=input[i]-48;
			s1.push(x);
			
		}
		else if(input[i]=='+' || input[i]=='-' ||input[i]=='*'||input[i]=='/')
		{
			a=s1.pop();
			b=s1.pop();
				switch(input[i])
				{
					case '+':c=b+a;
							s1.push(c);
							break;
					case '-':c=b-a;
							s1.push(c);
							break;
					case '*':c=b*a;
							s1.push(c);
							break;
					case '/':c=b/a;
							s1.push(c);
							break;			
				}
		}
	i++;
	}
	
	cout<<"Answer is "<<s1.pop()<<endl;
	return 0;
}

