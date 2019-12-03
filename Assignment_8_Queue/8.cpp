/*8. Write a program to implement queue using array. Implement functions for below operations.
a. Insert element in queue
b. Remove element from queue.
c. Print elements of queue.
d. Check if queue is full
e. Check if queue is empty.*/

#include<iostream>
using namespace std;

class Queue
{
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
	size=4;
	front=rear=-1;
	for(int i=0;i<=size;i++)
	{
		arr[i]=0;
	}
	
}
Queue::Queue(int s)
{
	size=s;
	
}
void Queue::insert(int n)
{
	int i,j;
	//cout<<front<<"front-------Rear"<<rear<<endl;
	if(!isfull())
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		arr[rear]=n;
		
	}
	
	
	else
	{
		cout<<"Overflow"<<endl;
	}
	
//	cout<<front<<"front-------Rear"<<rear<<endl;
	
}
void Queue::remove()
{

//	cout<<front<<"front-------Rear"<<rear<<endl;
	if(front < 4)
	{
		front++;
	}
	else
	{
		cout<<"underflow"<<endl;

	}
//	cout<<front<<"front-------Rear"<<rear<<endl;
	
}
void Queue::display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<arr[i]<<"-->";
	}
	cout<<endl;
	
}
bool Queue::isfull()
{
	
		return rear==size-1;	
}
bool Queue::isempty()
{

	return rear=front;
	
}

int main()
{
	int ch,n;
	Queue q;
	
	while(1)
	{
		cout<<"Enter the option:"<<endl;
		cout<<"1.Insert:"<<endl;
		cout<<"2.Remove:"<<endl;
		cout<<"3.Display:"<<endl;
		cout<<"4.Exit."<<endl;
		cin>>ch;
	switch(ch)
	{
		
		
		case 1:
				cout<<"Enter the Element:"<<endl;
				cin>>n;
			 	q.insert(n);
				break;
		case 2:
				q.remove();
				break;
		case 3: q.display();
				break;
		case 4:
				exit(0);
		
	}
		
	}

	
	return 0;
}
