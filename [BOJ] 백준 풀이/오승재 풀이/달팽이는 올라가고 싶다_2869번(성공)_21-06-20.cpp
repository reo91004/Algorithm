#include<iostream>
using namespace std;



int main()
{
	int a,b,v;
	cin>>a>>b>>v;
	
	//(a-b)(n-1)+a>=v
	//n-1>(v-a)/a-b	n>=(v-a)/(a-b)+1
	double n=static_cast<double>(v-a)/(a-b)+1;
	if(n!=static_cast<int>(n))
	{n++;}
		cout<<static_cast<int>(n)<<endl;
}