#include <iostream>
#include <cmath>

int main()
{
	int A,B,C;
	std::cin>>A>>B>>C;
	
	long long remainder=1;
	int root=sqrt(B);
	
	for(int i=0;i<root;i++)
	{
		remainder*=(A%C);
		remainder%=C;
	//	std::cout<<"i is "<<i<<" remainer is "<<remainder<<std::endl;
	}
	int temp=remainder;
	for(int i=1;i<root;i++)
	{
		remainder*=temp;
		remainder%=C;
	//	std::cout<<"i is "<<i<<" remainer is "<<remainder<<std::endl;
	}
	
	for(int i=root*root;i<B;i++)
	{
		remainder*=(A%C);
		remainder%=C;
	//	std::cout<<"i is "<<i<<" remainer is "<<remainder<<std::endl;	
	}	
	std::cout<<remainder;
	
	return 0;
}