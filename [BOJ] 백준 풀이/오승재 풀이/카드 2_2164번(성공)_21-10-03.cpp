#include <iostream>
#include <queue>


int main()
{
	int N;
	std::cin>>N;
		
	std::queue <int> Q;
	
	for(int i=1;i<=N;i++)
	{
		Q.push(i);	
	}
	//Input Data
	
	while(Q.size()>1)
	{
		Q.pop();
		Q.push(Q.front());
		Q.pop();	
	}
	
	std::cout<<Q.front();
	
	return 0;
}