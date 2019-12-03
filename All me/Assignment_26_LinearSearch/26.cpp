/*26. Write a program to search an element inside 
array using linear search*/

#include<iostream>
using namespace std;

int main()
{
	int i,n,f;
	int arr[100];
	cout<<"How many elements"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
	cout<<"Enter element to search "<<endl;
	cin>>f;
		for(i=1;i<=n;i++)
		{
			if(arr[i]==f)
			{
				cout<<"Index of searched element is:\t"<<i<<endl;
				break;
			}
		}
	return 0;
	
}
