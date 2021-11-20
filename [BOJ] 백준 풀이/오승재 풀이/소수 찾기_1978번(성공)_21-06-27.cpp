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
	int Case;
	cin>>Case;
	int decimal=0;
	for(int i=0;i<Case;i++)
	{int n;cin>>n;
		if(Isdecimal(n))
			decimal++;
	}	
	cout<<decimal<<endl;
}