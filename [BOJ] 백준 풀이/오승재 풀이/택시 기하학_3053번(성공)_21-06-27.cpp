#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int n;
	cin>>n;
	cout<<fixed;
	cout.precision(7);
	cout<<static_cast<long double>(n*n*M_PI)<<'\n';
	cout<<static_cast<long double>(n*n*2)<<endl;
}