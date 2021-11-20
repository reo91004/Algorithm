#include <iostream>
using namespace std;

int decomposition(int n)
{
	for(int i=1;i<n;i++)
	{
		int k=i;
		int sum=k;
		while(k)
		{sum+=k%10;
		k/=10;}
		if(sum==n)
			{return i;}
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	cout<<decomposition(n)<<endl;
}