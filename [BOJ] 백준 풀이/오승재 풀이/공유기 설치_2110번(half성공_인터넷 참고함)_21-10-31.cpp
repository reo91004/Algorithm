#include <iostream>
#include <algorithm>

int function(int arr[],int n,int c);
int count_router(int arr[],int n,int len);

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	int n,c;
	std::cin>>n>>c;
	int* arr= new int[n];
	
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];	
	}
	std::sort(arr,arr+n);
	
	std::cout<<function(arr,n,c);
	
	delete []arr;
	
	return 0;
}

int function(int arr[],int n,int c)
{
	int start=1;
	int end=arr[n-1]-arr[0];
	int mid,result=1;
	while(end>=start)
	{
		mid=(start+end)/2;
		int count=count_router(arr,n,mid);
		if(count>=c)
		{
			result=std::max(mid,result);
			start=mid+1;			
		}
		else if(count>c)//mid<answer
		{	start=mid+1;	}
		else//count<c //mid>answer
		{	end=mid-1;	}
	}
	return result;
}

int count_router(int arr[],int n,int len)
{
	int count=1;
	int prev_house=arr[0];
	for(int i=0;i<n;i++)
		{
			if(arr[i]-prev_house>=len)
			{	count++; prev_house=arr[i];	}	
		}
	return count;	
}