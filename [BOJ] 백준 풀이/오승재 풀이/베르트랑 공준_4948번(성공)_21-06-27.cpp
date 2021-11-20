#include <iostream>
#include <cmath>
using namespace std;


bool Isdecimal(int n)
{
	if(n==1)
		return false;
	if(n==2)
		return true;
		
	
	int srt=sqrt(n)+1;
	if(n%2==0)
		return false;
	for(int i=3;i<=srt;i+=2)
	{
		if(n%i==0)
			return false;
	}	
	return true;
	
}

int main()
{
	int input;
	while(1)
	{
		cin>>input;
		if(input==0)
			break;
		int sum=0;
		for(int i=input+1;i<=2*input;i++)
		{
			if(Isdecimal(i))
				sum++;
		}
		cout<<sum<<'\n';	
		}
	return 0;
}