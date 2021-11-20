#include <iostream>
#include <stack>

bool STR_Checker(std::string STR);


int main()
{
	int N;
	std::cin>>N;
	
	for(int i=0;i<N;i++)
	{
	std::string STR;
	std::cin>>STR;
	
	if(STR_Checker(STR))
		std::cout<<"YES"<<'\n';
	else
		std::cout<<"NO"<<'\n';	
	
	}
	return 0;
}

bool STR_Checker(std::string STR)
{
	std::stack<char> v ;
	
	for(int i=0;i<STR.size();i++)
	{
		if(STR[i]=='(')
			v.push(STR[i]);
		else
			{
				if(v.empty())
					return false;	
				else
					v.pop();
			}
	}	
	return v.empty();
}