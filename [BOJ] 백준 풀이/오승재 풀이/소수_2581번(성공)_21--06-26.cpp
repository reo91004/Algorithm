#include <iostream>
#include <cmath>
using namespace std;

bool Isdecimal(const int num)
{
	if(num==1)
		return false;
	if(num==2)
		return true;
	int n=sqrt(num);
	if(n*n==num)
	{}
	else
		n++;
	for(int i=2;i<=n;i++)
	{
		if(num%i==0)
			return false;
	}
	return true;
}

int main()
{
	int M,N;
	cin>>M>>N;
	int sum=0;
	int num=0;
	for(int i=M;i<N;i++)
	{
		if(Isdecimal(i))
			{sum+=i;
				if(num==0)
					num=i;
			}
	}	
	if(sum==0)
	{cout<<-1<<endl;}
	else
	{
	cout<<sum<<'\n'<<num<<endl;;
	}
}