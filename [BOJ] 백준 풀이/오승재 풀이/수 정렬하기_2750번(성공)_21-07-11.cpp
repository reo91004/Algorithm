#include <iostream>
using namespace std;

void swap(int& n,int& m)
{
	int temp=n;
	n=m;
	m=temp;	
}


int main()
{
	int n;
	cin>>n;
	int* arr=new int[n];	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);	
		}	
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<'\n';	
	}
	return 0;
}