#include <iostream>
#include <cstring>


int main()
{
	std::string s;
	std::cin>>s;
	
	int numstack[1000]={0,};
	char opstack[1000]={0,};
	int numcount=0;
	int opcount=0;
	int index=0;
	
	for(int i=0; i<s.length(); i++)
	{
		std::string temp;
		if(!isdigit(s.at(i)))
		{
			temp=s.substr(index,i-index);
			numstack[numcount++]=stoi(temp);
			opstack[opcount++]=s.at(i);
			index=i+1;
		}
		else if(i==s.length()-1)
		{
			temp=s.substr(index,i-index+1);
			numstack[numcount++]=stoi(temp);		
		}
	}
	
	
	int sum=numstack[0];
	index=0;
	while(index<=opcount)
	{
		if(opstack[index]=='-')
		{
			while(index<=opcount)
				sum-=numstack[++index];
		}
		else
			sum+=numstack[++index];	
	}
	std::cout<<sum;
	/*
	for(int i=0;i<numcount;i++)
		std::cout<<"numstack["<< i <<"]==" << numstack[i]<<std::endl;
		
	for(int i=0;i<opcount;i++)
		std::cout<<"opstack["<< i <<"]==" << opstack[i]<<std::endl;
		
	*/
	return 0;
}