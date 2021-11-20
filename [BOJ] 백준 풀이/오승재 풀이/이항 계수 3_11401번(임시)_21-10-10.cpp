//nCr=n-1Cr+n-1Cr-1
#include <iostream>
#define R 1000000007

int nCr(int n,int r);

int main()
{
	int N,K;
	std::cin>>N>>K;	

	
	std::cout<<nCr(N,K);
	
	return 0;	
}


int nCr(int n,int r)
{
	if(r==0||r==n)
		return 1;
	return (nCr(n-1,r)+nCr(n-1,r-1))%R;
	
}