#include <iostream>
#include <algorithm>


int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	int n,m;
	std::cin>>n;
	
		int* arr= new int [n];
		for(int i=0;i<n;i++)
			std::cin>>arr[i];
				
	std::cin>>m;
	
	std::sort(arr,arr+n);
	
	for(int i=0;i<m;i++)
	{
		int temp; 
		std::cin>>temp;
		
		if(std::binary_search(arr,arr+n,temp))
			std::cout<<"1\n";
		else
			std::cout<<"0\n";	
	}	
	
	delete []arr;
	
	return 0;	
}