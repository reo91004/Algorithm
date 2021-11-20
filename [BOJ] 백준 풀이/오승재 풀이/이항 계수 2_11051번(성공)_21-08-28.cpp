#include <iostream>

int nCk(int n,int k);

int main()
{
	int N,K;
	std::cin>>N>>K;
	
	int Binomial_Coefficient=nCk(N,K);
	
	std::cout<<Binomial_Coefficient%10007;	
	
	
}

int nCk(int n,int k)
{
	static int matrix[1000][1000]={{0,}};
	if(matrix[n][k]!=0)
		return matrix[n][k];
		
	if(k==0||k==n)
		{matrix[n][k]=1;}	
	else
	{
		matrix[n][k]=(nCk(n-1,k-1)+nCk(n-1,k))%10007;	
	}
	return matrix[n][k];
}