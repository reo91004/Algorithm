#include <iostream>
#include <algorithm>
#define idx 10000000

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
	
	int n,m;
	int number_of_card[2*idx+1]={};
	std::cin>>n;
	
	int* cards= new int[n];
	for(int i=0;i<n;i++)
	{
		int card; std::cin>>card;
		cards[i]=card; number_of_card[card+idx]++;	
	}
	
	std::cin>>m;
	
	for(int i=0;i<m;i++)
	{
		int card; std::cin>>card;
		std::cout<<number_of_card[card+idx]<<' ';
	}
	
	delete [] cards;
	
	return 0;
}