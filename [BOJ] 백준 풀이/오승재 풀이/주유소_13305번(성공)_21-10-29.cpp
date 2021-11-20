#include <iostream>


int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	int n;
	std::cin>>n;
	
	int* distances=new int[n-1]{};
	
	for(int i=0;i<n-1;i++)
		std::cin>>distances[i];
	
	
	int city=1000000000;
	long long cost=0;
	//Input Data
	
	for(int i=0;i<n;i++)
		{
			int temp; std::cin>>temp;
			city=std::min(city,temp);
			cost+=1LL*city*distances[i];	
		}
		
	std::cout<<cost;

	return 0;
}