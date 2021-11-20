#include <iostream>

int tile(int N);

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin>>N;
		
	std::cout<<tile(N);
	return 0;
}



int tile(int N)// O(n^2)
{
	int* mem;
	mem=new int[N];
	
	mem[0]=1; mem[1]=2;
	
	for(int i=2;i<N;i++)
	{
		mem[i]=mem[i-1]+mem[i-2];
		mem[i]%=15746;
	}	
	int num=mem[N-1];
	delete []mem;
	return num;
	
}
