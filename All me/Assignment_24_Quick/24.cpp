/*24. Write a program to sort the elements of array using quick sort*/


#include<iostream>
using namespace std;

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
void display(int arr [],int n)
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
		cout<<"4.Quick sort"<<endl;
		cout<<"5.Display"<<endl;
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
					quicksort(arr,0,n-1);
					break;
			case 5:		
					display(arr,n);
					break;
			case 0:
					exit(0);
		}
	}
	return 0;
}

