#include <iostream>
using namespace std;

int Fibo(int n)
{
	switch(n)
	{
		case 0:
			return 0;
		case 1:
			return 1;
		default:
			return Fibo(n-1)+Fibo(n-2);
	}
}

int main()
{
	int num;
	cin>>num;
	cout<<Fibo(num)<<endl;
	return 0;
}


