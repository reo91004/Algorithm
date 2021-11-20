#include <iostream>
#include <cmath>
using namespace std;


int HowManyTimesRequire(const int& x,const int& y)
{
	int distance =y-x;
	int n=sqrt(distance);
	if(n*n==distance)
	{return 2*n-1;}
	else if(distance<=n*n+n)
	{return 2*n;}
	else
	{return 2*n+1;}
	
	
}
int main()
{
	int Case;
	cin>>Case;
	for(int i=0;i<Case;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<HowManyTimesRequire(x,y)<<endl;
	}
}
	