#include <iostream>
#include <deque>

enum Menu{push_front,push_back,pop_front,pop_back,size,empty,front,back};
int Selection(std::string s);

void Push_front(std::deque <int>& DQ);
void Push_back(std::deque <int>& DQ);
void Pop_front(std::deque <int>& DQ);
void Pop_back(std::deque <int>& DQ);
void Size(std::deque <int>& DQ);
void Empty(std::deque <int>& DQ);
void Front(std::deque <int>& DQ);
void Back(std::deque <int>& DQ);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin>>N;
	
	std::deque <int> DQ;
	
	for(int i=0;i<N;i++)
	{
		std::string s;
		std::cin>>s;
		
		switch(Selection(s))
		{
			case push_front:
				Push_front(DQ); break;
			case push_back:
				Push_back(DQ); break;
			case pop_front:
				Pop_front(DQ); break;
			case pop_back:
				Pop_back(DQ); break;
			case size:
				Size(DQ); break;
			case empty:
				Empty(DQ); break;
			case front:
				Front(DQ); break;
			case back:
				Back(DQ); break;	
		}	
	}
		
	
}

int Selection(std::string s)
{
	if(s=="push_front")
		return push_front;
	else if(s=="push_back")
		return push_back;
	else if(s=="pop_front")
		return pop_front;
	else if(s=="pop_back")
		return pop_back;
	else if(s=="size")
		return size;
	else if(s=="empty")
		return empty;
	else if(s=="front")
		return front;
	else if(s=="back")
		return back;
	else
		return -1;
}

void Push_front(std::deque <int>& DQ)
{
	int n; std::cin>>n; DQ.push_front(n);	
}
void Push_back(std::deque <int>& DQ)
{
	int n; std::cin>>n;DQ.push_back(n);	
}

void Pop_front(std::deque <int>& DQ)
{
	if(DQ.empty())
		{std::cout<<-1<<'\n';}
	else
		{std::cout<<DQ.front()<<'\n';DQ.pop_front();}	
}
void Pop_back(std::deque <int>& DQ)
{
	if(DQ.empty())
		{std::cout<<-1<<'\n';}
	else
		{std::cout<<DQ.back()<<'\n';DQ.pop_back();}
}	
void Size(std::deque <int>& DQ)
{
	std::cout<<DQ.size()<<'\n';	
}

void Empty(std::deque <int>& DQ)
{
	if(DQ.empty())
		std::cout<<1<<'\n';
	else
		std::cout<<0<<'\n';
}

void Front(std::deque <int>& DQ)
{
	if(DQ.empty())
		{std::cout<<-1<<'\n';}
	else
		{std::cout<<DQ.front()<<'\n';}	
}

void Back(std::deque <int>& DQ)
{
	if(DQ.empty())
		{std::cout<<-1<<'\n';}
	else
		{std::cout<<DQ.back()<<'\n';}
}