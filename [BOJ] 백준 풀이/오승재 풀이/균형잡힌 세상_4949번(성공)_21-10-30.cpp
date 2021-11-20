#include <iostream>
#include <string>
#include <stack>

int main()
{	
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	
	while(true)
	{
		std::string str;
		std::stack<char> stk;

		bool balanced=true;
	
		getline(std::cin,str,'.');
	
		if(str=="")
			break;
		
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='(')
				{	stk.push('('); continue;	}
			else if(str[i]=='[')
				{	stk.push('['); continue;	}
				
			if(str[i]==')')
			{		
				if(!stk.empty()&&stk.top()=='(')
				{	stk.pop();	}
				else
				{	balanced=false;	break;	}
			}
			
			else if(str[i]==']')
			{		
				if(!stk.empty()>0&&stk.top()=='[')
				{	stk.pop();	}
				else
				{	balanced=false;	break;	}
			}		
		}
		if(!stk.empty()>0)
			{ balanced=false; }
		
		if(balanced)
			std::cout<<"yes\n";
		else
			std::cout<<"no\n";
		/*while(std::cin.get()!='\n')
		{}*/
		std::cin.ignore(); //cpp의 입력버퍼 지우는 함수
		}
	
	return 0;
}