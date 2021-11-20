#include <iostream>
#include <numeric>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int T;//number of TestCases
	std::cin>>T;
	
	for(int i=0;i<T;i++)
	{
		int num1, num2;
		std::cin>>num1>>num2;
		std::cout<<std::lcm(num1,num2)<<'\n';	
	}
	
	return 0;			
}