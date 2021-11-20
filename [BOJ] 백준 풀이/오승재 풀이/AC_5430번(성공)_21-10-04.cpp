#include <iostream>
#include <deque>
#include <string>

void InputDeque(std::deque <int>& DQ);
bool Dump(std::deque <int>& DQ,bool Reverse);//error면 return true;
void ShowDeque(std::deque <int>& DQ,bool Reverse);

int main()
{
	int T;
	std::cin>>T;//The number of Test Cases
	
	for(int i=0;i<T;i++)
	{
		std::string p; std::cin>>p; // 수행할 함수 p 
		int n; std::cin>>n;// 배열에 들어가있는 수의 개수
			
		std::deque <int> DQ;
		bool Reverse=false;
		InputDeque(DQ);//Input Data
		bool ERROR=false;
		
		//ShowDeque(DQ,Reverse);
		for(int j=0;j<p.length();j++)
		{
			if(p[j]=='R')
			{	Reverse=!Reverse;	}
			else //DQ[j]=='D'
			{	
				ERROR=Dump(DQ,Reverse);
				if(ERROR)
					{	std::cout<<"error\n"; break;}	
			}	
		}
		if(!ERROR)
		{	ShowDeque(DQ,Reverse);	}
		else
		{	DQ.clear();	}
	}
	return 0;
}



void InputDeque(std::deque <int>& DQ)
{
	std::string s;
	std::cin>>s;
	if(s.length()==2)
		return;
	int front, back=s.find('[');
	while(back!=s.length()-1)
	{	
		front=back+1; back=s.find(',',front);
		if(back>=s.length())
			{back=s.length()-1;}
		int temp=stoi(s.substr(front,back-front));
		//std::cout<<"temp is :"<<temp<<std::endl;
		DQ.push_back(temp);	
	}	
}

bool Dump(std::deque <int>& DQ,bool Reverse)//error면 return true; 즉 버릴수 없음
{
	if(DQ.empty())
	{	return true;	}
	else if(Reverse)
	{	DQ.pop_back();	}
	else//Not Reverse
	{	DQ.pop_front();	}
	
	return false;	
}

void ShowDeque(std::deque <int>& DQ,bool Reverse)
{
	if(DQ.empty())
	{
		std::cout<<"[]\n";
		return;	
	}
	if(Reverse)
	{
		std::cout<<'[';
		for(int i=DQ.size()-1;i>0;i--)
		{
			std::cout<<DQ[i]<<',';	
		}
		std::cout<<DQ[0]<<"]\n";
	}
	else
	{
		std::cout<<'[';
		for(int i=0;i<DQ.size()-1;i++)
		{
			std::cout<<DQ[i]<<',';	
		}
		std::cout<<DQ[DQ.size()-1]<<"]\n";
	}	
}