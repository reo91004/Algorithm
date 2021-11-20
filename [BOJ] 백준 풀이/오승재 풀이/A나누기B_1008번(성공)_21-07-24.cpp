#include <iostream>


int main()
{
	int a,b;
	std::cout.fixed;
	std::cout.precision(12);
	std::cin>>a>>b;
	std::cout<<static_cast<double>(a)/b<<std::endl;	
	return 0;
}