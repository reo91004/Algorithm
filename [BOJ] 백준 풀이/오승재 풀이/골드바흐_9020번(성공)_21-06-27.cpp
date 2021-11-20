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
void goldbach(int n);

int main()
{
		int event;
		cin>>event;
		for(int i=0;i<event;i++)
		{
			int num; 
			cin>>num;	
			goldbach(num);
		}
		return 0;
}
void goldbach(int n)
{
	if(n==4)
	{cout<<"2 2"<<'\n';return;}
	
	for(int i=n/2;i>=3;i--)
	{
		if(Isdecimal(i)&&Isdecimal(n-i))
		{cout<<i<<' '<<n-i<<'\n';return;}	
	}
		return ;			
}