#include <iostream>
#include <algorithm>

int* BinarySearch(int *first,int* last,int key);
int Number_Of_Keys(int* arr,int* last,int*key); 


int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
	
	int n,m;
	std::cin>>n;	
	
	int* arr=new int [n]{};
	for(int i=0;i<n;i++)
		std::cin>>arr[i];
		
	std::sort(arr,arr+n);
	//Input data&Sort data
	
	std::cin>>m;
	
	for(int i=0;i<m;i++)
	{
		int key; std::cin>>key;
		int*ptr=BinarySearch(arr,&arr[n-1],key);
		
		std::cout<<Number_Of_Keys(arr,&arr[n-1],ptr)<<' ';
			
	}
	
	delete []arr;
	
	return 0;
}

int* BinarySearch(int *arr,int* last,int key)
{
	int start=0;
	int end=last-arr;
		int mid;
	while(end-start>=0)
	{
		mid=(start+end)/2;
		
		if(arr[mid]==key)
			return &arr[mid];
		else if(arr[mid]>key)
			end=mid-1;
		else 
			start=mid+1;	
	}
	return NULL;
}

int Number_Of_Keys(int* arr,int* last,int*key)
{
	if(key==NULL)
		return 0;
	
	int *rptr, *lptr, *temp;
	rptr=lptr=temp=key;
	while(rptr!=NULL||rptr==last)
	{
		temp=rptr;
		rptr=BinarySearch(rptr+1,last,*key);
	}
	rptr=temp;
	
	while(lptr!=NULL||lptr==arr)
	{
		temp=lptr;
		lptr=BinarySearch(arr,lptr-1,*key);
	}
	lptr=temp;
	
	return rptr-lptr+1;
	//while(BinarySearch(arr,)
	
}