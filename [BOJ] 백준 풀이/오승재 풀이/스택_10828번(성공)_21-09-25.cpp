#include <iostream>
#include <vector>

enum{push,pop,size,empty,top};

int ConvertStr(std::string s);

void Push(std::vector <int>& v);
void Pop(std::vector <int>& v);
void Size(std::vector <int>& v);
void Empty(std::vector <int>& v);
void Top(std::vector <int>& v);

int main()
{
	
	std::vector <int> v;
	int n;
	std::cin>>n;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	for(int i=0;i<n;i++)
	{
		std::string S;
		std::cin>>S;
		switch(ConvertStr(S))
		{
			case push:
				Push(v);
				break;
			case pop:
				Pop(v);
				break;
			case size:
				Size(v);
				break;
			case empty:
				Empty(v);
				break;
			case top:
				Top(v);
			break;	
		}
	}
	
}


int ConvertStr(std::string s)
{
	if(s=="push")
		return push;
	else if(s=="pop")
		return pop;
	else if(s=="size")
		return size;
	else if(s=="empty")
		return empty;
	else
		return top;	
}

void Push(std::vector <int>& v)
{
	int n;
	std::cin>>n;
	v.push_back(n);
	return;	
}

void Pop(std::vector <int>& v)
{
	if(!v.empty())
	{
		std::cout<<v.back()<<'\n';
		v.pop_back();	
	}
	else
		std::cout<<-1<<'\n';
	return;
}

void Size(std::vector <int>& v)
{
	std::cout<<v.size()<<'\n';
	return;	
}

void Empty(std::vector <int>& v)
{
	if(v.empty())
		std::cout<<1<<'\n';
	else
		std::cout<<0<<'\n';
	return;
}

void Top(std::vector <int>& v)
{
	if(!v.empty())
	{
		std::cout<<v.back()<<'\n';	
	}
	else
		std::cout<<-1<<'\n';
	return;
}
