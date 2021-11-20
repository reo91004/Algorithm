#include <iostream>
#include <algorithm>




int main()
{
	int n;
	std::cin>>n;
	
	int arr[1000001]={0,};
	arr[1]=0; arr[2]=1;arr[3]=1;

	for(int i=4;i<=n;i++)
	{
		int min=arr[i-1];
		if(i%3==0){	min=std::min(arr[i/3],min);}
		if(i%2==0){	min=std::min(arr[i/2],min);}
		
		arr[i]=min+1;
		//std::cout<<"arr["<<i<<"]== "<<arr[i]<<std::endl;
	}

	std::cout<<arr[n];

	return 0;
}

