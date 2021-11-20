#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int n;
	int sum=0;
	
	std::cin>>n;
	
	int* arr= new int[n];
	for(int i=0;i<n;i++)
		std::cin>>arr[i];
	
	std::sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
	{
		sum+=arr[i]*(n-i);	
	}
	
	std::cout<<sum;
	
	delete []arr;
	
	return 0;
}