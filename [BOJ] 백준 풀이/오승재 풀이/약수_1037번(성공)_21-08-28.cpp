#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int number;
	std::cin>>number;
	
	int* arr= new int[number];
	for(int i=0;i<number;i++)
		std::cin>>arr[i];
		
	std::sort(arr,arr+number);
			
	std::cout<<arr[0]*arr[number-1];
	
	delete []arr;
	arr=NULL;
		
	return 0;
}