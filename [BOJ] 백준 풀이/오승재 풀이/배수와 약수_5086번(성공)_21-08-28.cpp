#include <iostream>

std::string Factor_Multiple_Neither(int num1,int num2);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int num1,num2;
	while(1)
	{	std::cin>>num1>>num2;
		if(num1==0&&num2==0)
			return 0;
					
		std::cout<<Factor_Multiple_Neither(num1,num2)<<'\n';
	}
}


std::string Factor_Multiple_Neither(int num1,int num2)
{
	if(num2%num1==0)
	{	return "factor";	}//num1==약수
	else if(num1%num2==0)
	{	return "multiple";	}//num1==배수
	else
	{	return "neither";	}//둘다 아님
}