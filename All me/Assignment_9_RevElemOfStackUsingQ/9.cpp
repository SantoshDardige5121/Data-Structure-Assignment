/*9. Reverse elements of stack using queue.*/




#include<iostream>
#define max 5
using namespace std;


class Stack
{
	int t[max];
	public:
			int top;
			void push(int);
			int pop();
			void display();
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
	int z=max;
	z--;
	if(top!=max-1)
	{
		top++;
		t[top]=e;
		cout<<e<<"<--- Is Pushed"<<endl;

	}
	else 
	
	{
			cout<<"Stack overflow"<<endl;
			
	}

}
int Stack::pop()
{	
	int z;
	if(top>=0)
	{
		cout<<t[top]<<"<--- Is Pooped"<<endl;
		
		
		return t[top--];
	}
	else 
	{
			cout<<"Stack overflow"<<endl;
	}
	
}

void Stack::display()
{
	for(int i=0;i<=top;i++)
	{
		cout<<"Element --- >"<<t[i]<<endl;		
	}	
}	




class Queue
{
	Stack s;
	
	int size;
	int front,rear;
	int arr[10];
	public:
			Queue();
			Queue(int);
			void insert(int);
			void remove();
			bool isfull();
			bool isempty();
			void display();
};
Queue::Queue()
{
	int i;
	size=max;
	front=rear=-1;
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
	
}
Queue::Queue(int s)
{
	size=s;
	
}
void Queue::insert(int e)
{
	int i,j;
	
	cout<<"element inserted in Queue"<<e<<endl;
	if(rear!=size-1)
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		arr[rear]=e;
		
	}
	
	

	
}
void Queue::remove()
{

	if(front < max)
	{
		front++;
	}
	else
	{
		cout<<"underflow"<<endl;

	}
	
}
void Queue::display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<arr[i]<<" "<<endl;
	}
	cout<<endl;
	
}

 int main()
 {
 	int a,e,n,z;
 	Stack s;
 	Queue q;
 	while(1)
 	{
 	
 		cout<<"Enter the option:\n1.Push\n2.Pop\n3.Display\n0.Exit"<<endl;
 		cin>>a;
 		
 
	switch(a)
	{
		
		
		case 1:
				cout<<"Enter the Element:"<<endl;
				cin>>n;
			 	s.push(n);
				break;
		case 2:
				z=s.pop();
				q.insert(z);
				break;
		case 3: cout<<"Enter the option:\n1.Stack display\n2.Queue display\n"<<endl; 
				cin>>e;
				if(e==1)
				{
						s.display();
				}
				else if(e==2)
				{
						q.display();
				}							
				break;
		case 4:
				exit(0);
		
	}	
}
	return 0;
	


}
 

