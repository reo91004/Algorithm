/*	a층의 b호에 살려면 
(a-1)층의 1호부터 b호까지 
사람들의 수의 합만큼 사람들을 
데려와 살아야한다*/
#include<iostream>
using namespace std;

int HowLives(int k,int n)//k층n호
{
	int sum=0;
	if(k==0)
	{return n;}
	for(int i=1;i<=n;i++)
	{
		sum+=HowLives(k-1,i);
	}	
	return sum;
}

int main()
{
	
		int Testcase;
		cin>>Testcase;
		for(int i=0;i<Testcase;i++)
		{
			int k,n;
			cin>>k>>n;
			cout<<HowLives(k,n)<<endl;	
		}
}