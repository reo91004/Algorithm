#include <iostream>

int main()
{
	int N,K;
	std::cin>>N>>K;
	
	int Binomial_Coefficient=1;//이항계수	
	
	for(int i=1;i<=K;i++)
	{
		Binomial_Coefficient*=N-i+1;
		Binomial_Coefficient/=i;	
	}
	
	std::cout<<Binomial_Coefficient;
	
	return 0;
}