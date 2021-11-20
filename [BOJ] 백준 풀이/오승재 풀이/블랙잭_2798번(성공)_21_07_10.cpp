#include <iostream>
using namespace std;

int Function(int n,int m,int arr[])
{
	int num=0;
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int sum=arr[i]+arr[j]+arr[k];
				if(sum<=m&&sum>num)
				{num=sum;}
			}	
		}
	}
	return num;
}
//n은 숫자의 개수 m은 만들어야할 숫자
int main()
{
	int n,m;
	cin>>n>>m;
	
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{cin>>arr[i];}
	cout<<Function(n,m,arr)<<endl;
}