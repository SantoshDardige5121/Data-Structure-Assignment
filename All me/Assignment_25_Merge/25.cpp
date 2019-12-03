/*25. Write a program to sort the elements of array using merge sort*/

#include<iostream>
using namespace std;

void insertionsort(int arr [],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(key<arr[j])
			{
				//arr[j]=key;
				arr[j+1]=arr[j];
			}
			else
				break;
			
		}
		arr[j+1]=key;
		
	}
	
}

int partition(int arr[],int lower,int upper)
{
	int i=lower-1;
	int j=lower;
	int temp;
	int pivot=arr[upper];
	while(j<upper)
	{
		if(arr[j]<pivot)
		{
			i=i+1;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		j++;
	}
		temp=arr[i+1];
		arr[i+1]=arr[upper];
		arr[upper]=temp;	
	return i+1;
}

void quicksort(int arr [],int lower,int upper)
{
	int q;
	if(lower<upper)
	{
		q=partition(arr,lower,upper);
		quicksort(arr,0,q-1);
		quicksort(arr,q+1,upper);	
	}
}
void selectionsort(int arr [],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	
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
void merge(int *arr,int low,int mid,int high)
{
	int i,j,k;
	int *temp;
	i=low;
	j=mid+1;
	k=0;
	temp=new int[high-low+1];
	
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else if(arr[j]<arr[i])
		{
			temp[k++]=arr[j++];
		}
		while(i<=mid)
		{
			temp[k++]=arr[i++];
		}
		while(j<=high)
		{
			temp[k++]=arr[j++];
		}
		for(i=low;i<=high;i++)
		{
			arr[i]=temp[i-low];
		}
		
	}	
}
void mergesort(int arr[],int low,int high)
{
	int mid;
	
	if (low<high)
	{   mid =(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	
		
}

void display(int arr[],int n)
{
	
	cout<<"Sorted elements"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<endl;
		}
	cout<<endl;
	
}



int main()
{
	int ch,i,j,n;
	int arr[100];
	cout<<"How many elements"<<endl;
	cin>>n;
	while(1)
	{
		cout<<"Choose the option:"<<endl;
		cout<<"1.Accept"<<endl;
		cout<<"2.Bubble sort"<<endl;
		cout<<"3.Selection sort"<<endl;
		cout<<"4.Insertion sort"<<endl;
		cout<<"5.Quick sort"<<endl;
		cout<<"6.Merge sort"<<endl;
		cout<<"7.Display"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"Enter the elements"<<endl;
					for(i=0;i<n;i++)
					{
						cin>>arr[i];
					}
								
					break;
			case 2:
					bubblesort(arr,n);
					break;
			case 3:
					selectionsort(arr,n);
					break;
			case 4:
					insertionsort(arr,n);
					break;
			case 5:
					quicksort(arr,0,n-1);
					break;
			case 6:		
					mergesort(arr,0,n-1);
					cout<<"Sorted elements"<<endl;
				
					break;
			case 7:		
					display(arr,n);
					break;
			case 0:
					exit(0);
		}
	}
	return 0;
}

