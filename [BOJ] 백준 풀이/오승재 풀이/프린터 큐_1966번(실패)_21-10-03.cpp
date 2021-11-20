#include <iostream>
#include <queue>
#include <algorithm>

class INT
{
	public:
		int num;
		bool checker;
		INT()
		{}
		INT(int num,bool checker):num(num), checker(checker)
		{}	
};
bool compare(int& n1,int& n2)
{
	return n1>=n2;	
}

int main()
{
	int T;
	std::cin>>T;
	
	for(int i=0;i<T;i++)
	{
		int N,M;
		std::cin>>N>>M;
		
		int* Priority=new int [N];
		std::queue <INT> Q;
		
		for(int j=0;j<N;j++)
		{
			std::cin>>Priority[j];
			INT temp;
			if(j==M)
			{	temp=INT(Priority[j],true); Q.push(temp);	}
			else
			{	temp=INT(Priority[j],false); Q.push(temp);	}	
		}
		//Input Data
		
		std::sort(Priority,Priority+N,compare);
		//quick sort Priority
		
		for(int j=0;j<N;j++)
		{
			while(Q.front().num<Priority[j])//우선순위 까지 돌아감
			{	Q.push(Q.front());	Q.pop();	}
			
			if(Q.front().checker)
			{	std::cout<<j+1<<'\n'; break;	}
			else
			{	Q.pop();	}			
		}
		while(!Q.empty())
			{Q.pop();}	
		delete []Priority;
		Priority=NULL;
	}
	
	return 0;			
}