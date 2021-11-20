#include<iostream>
using namespace std;


int main()
{
	int point[4];
	int count[4];
	
	cin>>point[0]>>point[2];
	count[0]=1;count[2]=1;
	
	for(int i=0;i<2;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==point[0])
			count[0]++;
		else
		{
			point[1]=x;
			count[1]++;
		}
		if(y==point[2])
			count[2]++;
		else
		{
			point[3]=y;
			count[3]++;
		}
	}
	for(int i=0;i<4;i++)
	{
		if(count[i]!=2)
		{cout<<point[i]<<' ';}	
	}
	cout<<endl;
	return 0;	
		
}