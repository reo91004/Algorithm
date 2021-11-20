#include <iostream>
#include <cmath>
using namespace std;


void Isdecimal(int n)
{
	if(n==1)
		return;
	if(n==2)
		cout<<2<<'\n';
		
	
	int srt=sqrt(n)+1;
	if(n%2==0)
		return;
	for(int i=3;i<=srt;i+=2)
	{
		if(n%i==0)
			return;
	}	
	cout<<n<<'\n';
	
}

int main()
{
	int M,N;
	cin>>M>>N;
	
	for(int i=M;i<=N;i++)
	{
		Isdecimal(i);	
	}
	return 0;		
}