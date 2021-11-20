#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#define fs first
#define sd second
#define Pair std::pair <int,bool>

void queue_clear(std::queue<Pair> &q);

int main()
{
	int t;
	std::cin>>t;
	//t is the number of test cases
	std::queue <Pair> que;
	
    for(int i=0;i<t;i++)
	{
		int n,m;
		int priority_arr [9]{};
		std::cin>>n>>m;
		
		for(int j=0;j<n;j++)
		{
			int priority; std::cin>>priority;
			priority_arr[priority-1]++;
			if(j==m)			
				{	que.push(std::make_pair(priority,true));	}
			else
				{	que.push(std::make_pair(priority,false));	}	
		}
		//Input Data
		
		int now_priority=9, sequence=1;
		
		while(true)
		{
			while(now_priority>=1&&priority_arr[now_priority-1]<=0)
			{now_priority--;}
			
			while(que.front().fs!=now_priority)
			{	que.push(que.front()); que.pop();	}
			
			if(que.front().sd==true)//priority가 일치하고 내가 찾는 순서의 요소이다
			{	break;	}
			else//que.front().sd==false
			{	que.pop(); priority_arr[now_priority-1]--; sequence++;	}
		}
		
		std::cout<<sequence<<'\n';
		queue_clear(que);
	}	
	
	return 0;
}

void queue_clear(std::queue<Pair> &q)
{
	std::queue<Pair> empty;
	std::swap(q,empty);	
}