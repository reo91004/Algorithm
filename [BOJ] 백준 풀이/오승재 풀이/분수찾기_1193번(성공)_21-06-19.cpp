#include<iostream>
using namespace std;

bool discriminator(int num,int n)
{
	if(num>n*(n-1)/2&&num<=n*(n+1)/2)//num이 {S(n-1)==n*(n-1)}과S(n)사이에 있음 즉 num이 n단계에 존재함
		{return false;}
	return true;	
}

int main()
{
	int num;
	cin>>num;
	int n=2;
	if(num==1)
	{cout<<"1/1"<<endl;return 0;}	
	while(discriminator(num,n))
	{
		n++;		
	}
	//cout<<n<<endl;
	if(n%2==0)
	{cout<<num-(n*(n-1)/2)<<"/"<<n+1-(num-(n*(n-1)/2))<<endl;}
	else
	{cout<<n+1-(num-(n*(n-1)/2))<<"/"<<num-(n*(n-1)/2)<<endl;}
	return 0;
}
