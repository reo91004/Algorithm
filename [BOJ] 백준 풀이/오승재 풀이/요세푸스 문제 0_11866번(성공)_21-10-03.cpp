#include <iostream>
#include <queue>


int main()
{
	int N,K;
	std::cin>>N>>K;
	
	std::queue <int> Q;
	std::queue <int> Josephus;
	
	for(int i=1;i<=N;i++)
	{
		Q.push(i);		
	}
	
	while(!Q.empty())
	{
		for(int i=0;i<K-1;i++)
		{
			Q.push(Q.front());
			Q.pop();	
		}
		Josephus.push(Q.front());
		Q.pop();
	}
	
	std::cout<<'<';
	
	while(Josephus.size()>1)
	{
		std::cout<<Josephus.front()<<", ";
		Josephus.pop();	
	}
	std::cout<<Josephus.front()<<'>';
	return 0;
}