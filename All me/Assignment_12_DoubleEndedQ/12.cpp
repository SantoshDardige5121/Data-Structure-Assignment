/*12. Write a program to implement double ended queue with array i.e. de-queue. 
Implement operationsa.
a. Insert from front end
b. Insert from rear end
c. Remove from front end
d. Remove from rear end
e. Check if queue is full
f. Check if queue is empty

*/


#include<iostream>
using namespace std;

class Queue
{
	int size;
	int front,rear;
	int front2,rear2;
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
	size=5;
	front=rear=-1;
	front2=rear2=size;
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
	int i,j,o;
	cout<<"Choose 1.From front\t2.From back"<<endl;
	cin>>o;
	if(o==1)
	{
		if(!isfull())
		{
			if(front==-1)
			{
				front=0;
			}
			rear++;
			arr[rear]=n;
				cout<<front<<"front-------Rear"<<rear<<endl;

		}
		
		
		else
		{
			cout<<"Overflow"<<endl;
		}
	}
	else if(o==2)
	{
		if(!isfull())
		{
			if(front2==size)
			{
				front2=size-1;
			}
			rear2--;
			arr[rear2]=n;
			
		}
		
		
		else
		{
			cout<<"Overflow"<<endl;
		}
	}
	
	
}
void Queue::remove()
{
	int o;
	cout<<"Choose 1.From front\t2.From back"<<endl;
	cin>>o;
	if(o==1)
	{
		if(front < rear2)
		{
			front++;
		}
		else
		{
			cout<<"underflow"<<endl;
	
		}
	}
	else if(o==2)
	{
		if(front2 > rear)
		{
			front2--;
		}
		else
		{
			cout<<"underflow"<<endl;
	
		}
	}

	
}
void Queue::display()
{
	int o;
	
	for(int i=front;i<=front2;i++)
	{
		cout<<arr[i]<<" "<<endl;
		
	}
	cout<<endl;
	
}
bool Queue::isfull()
{
		return rear2-rear==1;	
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


