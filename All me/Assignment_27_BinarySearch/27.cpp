/*27. Write a program to search an element inside array using binary search*/



#include<iostream>
using namespace std;

int binarysearch(int arr [],int n,int e)
{
	int mid,low,high;
	low=0;
	high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(arr[mid]==e)
		{
			return mid;
		}
		else if(arr[mid]<e)
		{
			low=mid+1;
		}
		else if(arr[mid]>e)
		{
			high=mid-1;
		}
	}
	return -1;
}

void bubblesort(int arr [],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
		
}

int main()
{
	int i,n,z,e;
	int arr[100];
	cout<<"How many elements"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		bubblesort(arr,n);
		cout<<"Sorted elements"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<endl;
		}
	cout<<endl;
	cout<<"Enter element to search "<<endl;
	cin>>e;
	
	z=binarysearch(arr,n,e);
	if(z!=-1)
	{
		cout<<"searched element index is: "<<z<<endl;
	}
	else
	{
		cout<<"Element not found"<<endl;
	}
	
	
	
		
	return 0;
	
}
