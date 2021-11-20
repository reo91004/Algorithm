#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

void Find_M(int arr[],int len);
int Find_GCD(int arr[],int len);
void Find_Divisor(int N);
int main()
{
	int len;
	std::cin>>len;
	
	int* arr= new int [len];
	for(int i=0;i<len;i++)
	{
		std::cin>>arr[i];	
	}
	
	std::sort(arr,arr+len);
	
	Find_M(arr,len);
	
	delete []arr;
	arr=NULL;
	
	return 0;		
}


void Find_M(int arr[],int len)
{
	int GCD=Find_GCD(arr,len);
	
	Find_Divisor(GCD);
	
	return ;
}

int Find_GCD(int arr[],int len)
{
	int GCD;
	if(len<=2)
	{
		GCD=arr[1]-arr[0];	
	}
	else
	{
		GCD=std::gcd(arr[2]-arr[1],arr[1]-arr[0]);
	}
	
	for(int i=3;i<len;i++)
	{
		GCD=std::gcd(arr[i]-arr[i-1],GCD);	
	}	
	return GCD;
}


void Find_Divisor(int N)
{
	int* arr=new int [static_cast<int>(std::sqrt(N))*2+1];
	
	int count=0;
	
	for(int i=2;i*i<=N;i++)
	{
		if(N%i==0)
		{
			arr[count++]=i;	
		}	
	}
	int temp=count;
	
	for(int i=0;i<temp;i++)
	{
		arr[count++]=N/arr[i];	
	}
	arr[count++]=N;
	
	std::sort(arr,arr+count);
	
	for(int i=0;i<count;i++)
	{
		if(i==0||arr[i]!=arr[i-1])
			std::cout<<arr[i]<<' ';	
	}
	
	delete []arr;
	arr=NULL;
	
	return ;
}