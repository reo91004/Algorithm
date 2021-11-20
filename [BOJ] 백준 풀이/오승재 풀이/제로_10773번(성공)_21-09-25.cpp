#include <iostream>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::vector <int> v;
	int K;
	std::cin>>K;
	
	for(int i=0;i<K;i++)
	{
		int Case;
		std::cin>>Case;
		
		switch(Case)
		{
			case 0:
				if(!v.empty())
					v.pop_back();
				break;
			default :
				v.push_back(Case);		
		}	
	}
	
	int Sum=0;
	for(int i=0;i<v.size();i++)
		Sum+=v[i];
		
	std::cout<<Sum;
	
	return 0;
}