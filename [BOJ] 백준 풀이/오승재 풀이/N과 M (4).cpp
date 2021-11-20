/* 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열*/
#include <iostream>
#define ARRMAX 8

class stack
{
	public:
	int num;
	int max;
	int arr[ARRMAX];
	stack(int num,int max):num(num), max(max)
	{
		for(int i=0;i<ARRMAX;i++)
		{
			arr[i]=0;	
		}	
	}	
};


void loop(int n,int m,int& count,stack& S,int last)
{
	if(count>m)
		return;
	for(int i=last;i<n;i++)
	{
		S.arr[count++]=i+1;
		loop(n,m,count,S,i);
		S.arr[--count]=0;
		
		if(count==m&&i==n-1)
			{
				for(int j=0;j<m;j++)
				{
					std::cout<<S.arr[j]<<' ';	
				}	
				std::cout<<'\n';
			}
		
	}	
}	
	



int main()
{
	int n,m;
	std::cin>>n>>m;
	
	//반복문을 n에 맞추어서 불러내는 방법은 없을까?
	stack S(0,ARRMAX);
	int count=0;
	
	loop(n,m,count,S,0);
	return 0;
}