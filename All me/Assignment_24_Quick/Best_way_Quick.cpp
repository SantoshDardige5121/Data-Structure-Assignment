/*Ouick Sort Prcatice*/


#include<iostream>
using namespace std;

int partation(int a[],int low,int up)
{
	int paivot,start,end;
	paivot=a[low];
	start=low;
	end=up;
	while(start < end)
	{
		
		while(a[start]<=paivot)
		{
			start++;
		}
		while(a[end]>paivot)
		{
			end--;
		}
		if(start<end)
		{
			int temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
			int temp=a[low];
			a[low]=a[end];
			a[end]=temp;
		return end;
	
	
	
	
}

void quick(int a[],int low,int up)
{
	int loc;
	if(low<up)
	{
		loc=partation(a,low,up);
		quick(a,low,loc-1);
		quick(a,loc+1,up);
	}
}
int main()
{
	int n,low,up;
	
	cout<<"Enter The Size"<<endl;
	cin>>n;
	
	int a[n];
	cout<<"Enter The Elements In Array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	low=0;
	up=n-1;
	quick(a,low,up);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" <> ";
	}
	cout<<endl;
	
	
	return 0;
	
}
