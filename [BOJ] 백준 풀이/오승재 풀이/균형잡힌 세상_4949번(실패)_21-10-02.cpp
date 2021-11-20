#include <iostream>
#include <string>
#include <stack>


int Switching(std::string S,int&idx);//아무것도 아니면 return -1


int main()
{
	
	while(1)
	{
		bool xscape=true;
		int idx=0;
		std::string S;
		std::stack <char> STK;
		
		std::getline(std::cin,S,'.');
		std::cin.ignore(100,'\n');
			if(S=="")
			{return 0;}
		//input std::string S

		//std::cout<<"S is a :"<<S<<std::endl;
		while(idx<S.length()&&xscape)
		{
			
			switch(Switching(S,idx))
			{
				case 0://	[
					STK.push('[');	idx++;	
					break;
				case 1://	]
					if(!STK.empty()&&STK.top()=='[')	{	STK.pop();	idx++;	}
						else {	xscape=false;	}
					break;
				case 2://	(
					STK.push('(');	idx++;	
					break;
				case 3://	)
					if(!STK.empty()&&STK.top()=='(')	{	STK.pop();	idx++;	}
						else {	xscape=false;	}
					break;
				default:
					idx++;
			}
		}
		
		if(xscape)
			{	std::cout<<"yes\n";	}
		else
			{	std::cout<<"no\n";	}
		while(!STK.empty())
			{	STK.pop();	}
			
	}	
	
}

int Switching(std::string S,int&idx)
{
	if(idx>=S.length())
		return -1;
	if(S[idx]=='[')
		{	return 0;	}
	else if(S[idx]==']')
		{	return 1;	}
	else if(S[idx]=='(')
		{	return 2;	}
	else if(S[idx]==')')
		{	return 3;	}
	
	return -1;				
}