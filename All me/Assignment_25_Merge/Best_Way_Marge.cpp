/*Marge Sort Easy Way*/

#include<iostream>
using namespace std;

void marge(int a[],int lb,int mid,int ub)
{
	int i,j,k;
	i=lb;
	j=mid+1;
	k=lb;
	int b[30];
	
	
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
/*	for(i=0;i<ub;i++)
	{
		cout<<b[i]<<"  ";
	}*/

	for(int t=ub;t>=lb;t--)
	{
		a[t]=b[--k];
	}
	
	
	
}
void margeSort(int a[],int lb,int ub)
{	
	int mid,i;
	if(lb<ub)
	{	mid=(lb+ub)/2;
		margeSort(a,lb,mid);
		for(i=0;i<=ub;i++)
		{
			cout<<a[i]<<"  ";
		}
		cout<<"  <-- MargeSort 1 Stage";
		cout<<endl;
		cout<<endl;
		margeSort(a,mid+1,ub);
		for(i=0;i<=ub;i++)
		{
			cout<<a[i]<<"  ";
		}
		cout<<"  <-- MargeSort 2 Stage";
		cout<<endl;
		cout<<endl;
		marge(a,lb,mid,ub);
		for(i=0;i<=ub;i++)
		{
			cout<<a[i]<<"  ";
		}
		cout<<"  <-- Marge Stage";
		cout<<endl;
		cout<<endl;
		
	}
	
}

int main()
{
	int n,ch,i;
	int lb,ub;
	cout<<"Enter Size Of Array"<<endl;
	cin>>n;
	int a[n];
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	lb=0;
	ub=n-1;
	margeSort(a,lb,ub);
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" <> ";
	}
	cout<<endl;
	return 0;
	
}
