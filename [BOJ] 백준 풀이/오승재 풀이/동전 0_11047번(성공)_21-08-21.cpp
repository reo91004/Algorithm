#include <iostream>


int main()
{
	int n,money;
	std::cin>>n>>money;
	
	int* Coin= new int[n];
	for(int i=0;i<n;i++)
		std::cin>>Coin[i];
		
	int count=0;
	
	while(money>0)
	{
		for(int i=n-1;i>=0;i--)
		{
			if(Coin[i]<=money)
			{
				int per=money/Coin[i];
				money-=Coin[i]*per;
				count+=per;	
			}	
		}	
	}		
	
	std::cout<<count;
	delete []Coin;
	
	return 0;
}