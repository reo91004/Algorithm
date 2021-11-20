#include <iostream>

long long nCk(int n,int k);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int T;
	std::cin>>T;
	
	for(int i=0;i<T;i++)
	{
		int N,M;
		std::cin>>N>>M;
		std::cout<<nCk(M,N)<<'\n';	
	}
	
	return 0;
}

long long nCk(int n,int k)
{
	static long long matrix[31][31]={{0,}};
	if(matrix[n][k]!=0)
		return matrix[n][k];
		
	if(k==0||k==n)
		{matrix[n][k]=1;}	
	else
	{
		matrix[n][k]=(nCk(n-1,k-1)+nCk(n-1,k));	
	}
	return matrix[n][k];
}