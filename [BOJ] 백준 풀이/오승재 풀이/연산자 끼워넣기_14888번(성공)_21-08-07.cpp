#include <iostream>

void MaxNMin(int arr[],int len,int op[],int idx,int num);
int Calculate(int n1,int n2,int C);

int main()
{
	int n;
	std::cin>>n;
	int* arr=new int [n];
	
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];	
	}
	
	int op[4]={0,};
	for(int i=0;i<4;i++)
	{
		std::cin>>op[i];	
	}

	MaxNMin(arr,n,op,0,0);
	
	delete []arr;
	
	return 0;
}

void MaxNMin(int arr[],int len,int op[],int idx,int num)
{
	static int max;
	static int min;
	static bool first=true;
	if(idx==0)
	{
		num=arr[0];	
	}
	if(idx>=len-1)
		{
			if(num>max||first)
				max=num;
			if(num<min||first)
				min=num;
			first=false;
			return;
		}
	
	for(int i=0;i<4;i++)
	{
		if(op[i]>0)
		{
			op[i]--;
			MaxNMin(arr,len,op,idx+1,Calculate(num,arr[idx+1],i));
			op[i]++;	
		}	
	}
	if(idx==0)
	{
		std::cout<<max<<'\n'<<min;	
	}
	return;
}

int Calculate(int n1,int n2,int C)
{
	switch(C)
	{
		case 0:
			return n1+n2;
		case 1: 
			return n1-n2;
		case 2:
			return n1*n2;
		case 3:
			return n1/n2;	
	}	
}