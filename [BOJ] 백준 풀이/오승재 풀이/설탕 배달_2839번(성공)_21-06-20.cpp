#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;	
	if(N%5==0)
	{
		cout<<N/5<<endl;
	return 0;
	}
	int five=0;
	
	five=(N/5);N=N-(five*5);
	if(N%3==0)
	{
		cout<<five+(N/3)<<endl;
		return 0;
	}
	//5키로 자루에 다 넣고 남은걸 보는 중
	for(int i=0;i<3;i++)
	{
		five-=1;N+=5;
		if(five<0)
		{cout<<-1<<endl;return 0;}
		if(N%3==0)
		{cout<<five+(N/3)<<endl; return 0;}
	}
	cout<<-1<<endl;
	return 0;
}