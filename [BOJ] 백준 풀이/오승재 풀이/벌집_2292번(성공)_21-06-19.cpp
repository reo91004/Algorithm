/*겉 껍질은 n단계일때(이때 1을 0단계라 가정한다) 껍질을 이루는 숫자들은
1 6 12 18 24 30즉 0단계를 제외하고는 6n이다. */
#include<iostream>
using namespace std;

bool discriminator(int num,int n)
{
	if(3*((n-1)*n)+1<num&&num<=3*((n+1)*n)+1)
	{return true;}
	
	return false;
}

int main()
{
	int num;
	cin>>num;
	int n=1;
	if(num==1)
	{
	cout<<'1'<<endl;
	return 0;
	}
	while(!discriminator(num,n))
	{
		n++;
	}

	cout<<n+1<<endl;
}

