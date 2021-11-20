#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin>>n;
	
	int* arr= new int [n];
	int* Max= new int[n]{0,};
	
	for(int i=0;i<n;i++)
		std::cin>>arr[i];
	Max[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		Max[i]=std::max(arr[i],Max[i-1]+arr[i]);
	
	}
	
	int max=-1001;
	for(int i=0;i<n;i++)
	{
	 max=std::max(Max[i],max);	
	}	
	
	std::cout<<max;
	delete []arr;
	delete []Max;
	
	return 0;
}