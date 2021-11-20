#include <iostream>
#include <algorithm>

int* findmin(int city[],int n);

int main()
{
	int n;
	std::cin>>n;
	
	int* distance= new int[n-1];
	int* city=new int[n];

	for(int i=0;i<n-1;i++)
		std::cin>>distance[i];
	
	for(int i=0;i<n;i++)
		{std::cin>>city[i];}
	
	long long sum=0;
	int index=n-1;
	do
	{
		int* temp=findmin(city,index);
		
		for(int p=temp-city;p<index;p++)
		{
			sum+=*temp *static_cast<long long>(distance[p]);
		}
		index=temp-city;
			
	}while(index>0);
	
	std::cout<<sum;
					
	delete []distance;
	delete []city;
			
	
	return 0;
}

int* findmin(int city[],int n)
{
	int* min=NULL;
	for(int i=0;i<n;i++)
	{
		if(min==NULL||*min>city[i])
			min=&city[i];	
	}
	return min;	
}