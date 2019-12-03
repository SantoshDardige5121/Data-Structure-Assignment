#include<iostream>
using namespace std;

class Element
{
	int data;
	int priority;
public:
	Element(int=0, int=0);
	void setdata(int);
	int getdata();
	void setpriority(int);
	int getpriority();
	void show();
};

void Element::show()
{
	cout<<"data: "<<data<<"  priority: "<<priority<<endl;
}

Element::Element(int d, int p)
{
	data=d, priority=p;
}

void Element::setdata(int d)
{
	data = d;
}

int Element::getdata()
{
	return data;
}

void Element::setpriority(int p)
{
	priority=p;
}

int Element::getpriority()
{
	return priority;
}

class pqueue
{
	int size;
	Element arr[50];
	int front, rear;
public:
	pqueue();
	pqueue(int);
	void insert(Element);
	Element remove();
	bool isfull();
	bool isempty();
};

pqueue::pqueue()
{
	size=5;
	front=rear=-1;	
}

pqueue::pqueue(int s)
{
	size=s;
	front=rear=-1;	
}

void pqueue::insert(Element e)
{
	int i;
	if(!isfull())
	{
		if(rear==-1)
		{
			arr[++rear]=e;
		}
		else
		{
			for(i=rear; i>=front+1 && (arr[i].getpriority()>e.getpriority()); i--)
			{
				arr[i+1]=arr[i];
			}	
			arr[i+1]=e;
			rear++;				
		}
	}
	else		cout<<"queue is full!!!"<<endl;
}

Element pqueue::remove()
{
	if(!isempty())
	{
		return arr[++front];
	}
	else
	{
		cout<<"queue is empty !!"<<endl;
		return Element(0,0);
	}
}

bool pqueue::isfull()
{
	return rear==size-1;
}

bool pqueue::isempty()
{
	return rear==front;
}

int main()
{
	pqueue pq;
	
	int i,d,p,ch,cnt=0;
	while(1)
	{
		cout<<"Enter the choice"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"Enter the Data & priority"<<endl;
					cin>>d;
					cin>>p;
					pq.insert(Element(d,p));
					cnt++;
					break;
			case 2:
				for(i=0;i<cnt;i++)
				{
					pq.remove().show();
				}
					break;
			case 0:
					exit(0);	
		}
	/*	
	}
	
	pq.insert(Element(10,5));
	pq.insert(Element(20,2));
	pq.insert(Element(30,4));
	pq.insert(Element(40,4));
	pq.insert(Element(50,6));
//	pq.insert(Element(60,9));

	pq.remove().show();
	pq.remove().show();
	pq.remove().show();
	pq.remove().show();
	pq.remove().show();
//	pq.remove().show();
*/
	
}
return 0;
}

