#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int num=1,count=0;
	while(count<n)
	{
		int i=num;
		while(i)
		{
			int n=i;
			if(n%10==6)
			{
				n/=10;
				if(n%10==6)
				{
					n/=10;
					if(n%10==6)
					{count++;break;}
				}
			}
			i/=10;	
		}
		if(count==n)
		{cout<<num<<endl;}
		num++;
	}
}