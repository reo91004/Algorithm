#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin>>n;
	
	int* arr= new int[n];
	for(int i=0;i<n;i++)
		std::cin>>arr[i];
	
	int* arr0= new int[n];//count==0 arr[i]::X
	int* arr1= new int[n];//count==1 arr[i]::O, arr[i-1]::X
	int* arr2= new int[n];//count==2 arr[i]::O, arr[i-1]::O, arr[i-2]::X
	arr0[0]=0; arr1[0]=arr2[0]=arr[0];
	arr0[1]=arr[0]; arr1[1]=arr[1]; arr2[1]=arr[0]+arr[1];
	
	 
	 for(int i=2;i<n;i++)
	 {
	 	arr0[i]=std::max(std::max(arr0[i-1],arr1[i-1]),arr2[i-1]);
	 	arr1[i]=arr0[i-1]+arr[i];
	 	arr2[i]=arr1[i-1]+arr[i];		 		
	 }
	 		 		
	 		 		
	std::cout<<std::max(std::max(arr0[n-1],arr1[n-1]),arr2[n-1]);
	
	delete []arr;
	delete []arr0;
	delete []arr1;
	delete []arr2;
	
	return 0;
}