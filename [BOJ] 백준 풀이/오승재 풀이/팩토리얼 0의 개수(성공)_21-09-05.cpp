#include <iostream>


int main()
{
	int N;
	int Count_Two=0, Count_Five=0;
	
	std::cin>>N;
	
	for(int i=N;i>1;i--)
	{
		int k=i;
		while(k%2==0)
		{	Count_Two++; k/=2;	}	
		while(k%5==0)
		{	Count_Five++; k/=5;	}
	}
	
	std::cout<<std::min(Count_Two,Count_Five);	
}