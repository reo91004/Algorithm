#include <iostream>
#include <queue>

enum Menu{push,pop,size,empty,front,back};
int CaseSwitch(std::string s);

void Push(std::queue <int>&Q);
void Pop(std::queue <int>&Q);
void Size(std::queue <int>&Q);
void Empty(std::queue <int>&Q);
void Front(std::queue <int>&Q);
void Back(std::queue <int>&Q);


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::queue <int> Q;
 	
	int N;
	std::cin>>N;
	
	for(int i=0;i<N;i++)
	{
		std::string s;
		std::cin>>s;
		switch(CaseSwitch(s))
		{
			case push:
				Push(Q);	break;
			case pop:
				Pop(Q);	break;
			case size:
				Size(Q);	break;
			case empty:
				Empty(Q);	break;
			case front:
				Front(Q);	break;
			case back:
				Back(Q);	break;	
		}
	}


	return 0;	
}


int CaseSwitch(std::string s)
{
	if(s=="push")	return push;
	else if(s=="pop")	return pop;
	else if(s=="size")	return size;
	else if(s=="empty")	return empty;
	else if(s=="front")	return front;
	else if(s=="back")	return back;
	else	return -1;	
}


void Push(std::queue <int>&Q)
{
	int n;
	std::cin>>n;	Q.push(n);	
}

void Pop(std::queue <int>&Q)
{
	if(Q.empty())	{	std::cout<<-1<<'\n';	}	
	else	{	std::cout<<Q.front()<<'\n';	Q.pop();	}
}

void Size(std::queue <int>&Q)
{
	std::cout<<Q.size()<<'\n';	
}

void Empty(std::queue <int>&Q)
{
	if(Q.empty())		{	std::cout<<1<<'\n';	}
	else		{	std::cout<<0<<'\n';	}	
}

void Front(std::queue <int>&Q)
{
	if(Q.empty())	{	std::cout<<-1<<'\n';	}	
	else	{	std::cout<<Q.front()<<'\n';	}
}

void Back(std::queue <int>&Q)
{
	if(Q.empty())	{	std::cout<<-1<<'\n';	}	
	else	{	std::cout<<Q.back()<<'\n';	}
}