#include <iostream>
using namespace std;


int main()
{
	int n;
	int div=2;
	cin>>n;
	while(n!=1)
	{
		if(n%div==0)
		{
			cout<<div<<endl;
			n/=div; div=2;	
		}
		else
		{
			div++;
		}
	}	
	
	return 0;
}