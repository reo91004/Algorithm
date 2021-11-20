#include<iostream>
using namespace std;

int main()
{
	int customers,h,w,n;
	cin>>customers;
	for(int i=0;i<customers;i++)
	{
		cin>>h>>w>>n;
		//room num=YYXX,YY==((n-1)%h)+1,XX==(n-1/h)+1
		if((n-1)/h+1<10)
			{cout<<((n-1)%h)+1<<'0'<<((n-1)/h)+1<<endl;}
		else
			{cout<<((n-1)%h)+1<<((n-1)/h)+1<<endl;}
	}	
}