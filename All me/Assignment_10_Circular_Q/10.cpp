/*10. Implement circular queue using array 
with all operations mentioned in question */

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
			int remove();
			bool isfull();
			bool isempty();
			void display();
};
Queue::Queue()
{
	int i;
	size=4;
	front=rear=size-1;
	for(int i=0;i<size;i++)
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
	cout<<front<<"front-------Rear"<<rear<<endl;
	if(!isfull())
	{
		if(front==size-1)
		{
			front=0;
		}

			rear=(rear+1)%size;
			arr[rear]=n;
		
	}
	
	
	else
	{
		cout<<"Overflow"<<endl;
	}
	
	cout<<front<<"front-------Rear"<<rear<<endl;
	
}
int Queue::remove()
{
	int i,j;
	cout<<front<<"front-------Rear"<<rear<<endl;
	if(!isempty())
	{
		//arr[front]=0;
		front=(front+1)%size;
		return arr[front];					
	}
	else
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	cout<<front<<"front-------Rear"<<rear<<endl;

	
	
}
void Queue::display()
{
for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	}
	
}
bool Queue::isfull()
{
	
		return front==(rear+1)%size;	
}
bool Queue::isempty()
{

	return (front==rear);
	
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
