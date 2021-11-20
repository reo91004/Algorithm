#include <iostream>
#include <utility>
#include <string>
#define Anum 26
#define fs first
#define sd second
#define Pair std::pair <int,int>
//Pair <공통된 알파벳의 갯수,함수가 처음 접근해야하는 문자의 인덱스>
int Find_LCS(std::string& s1,std::string& s2,bool CommonAlphabet[],int count,Pair P );//s1.length()>s2.length bool arr []은 공통된 알파벳인지 검토함

int main()
{
	std::string s1,s2;
	
	std::cin>>s1>>s2;
	//Input Data
	//std::cout<<s1<<'\n'<<s2<<std::endl;//check Data
	
	bool s1Alphabet [Anum]{false,};
	bool s2Alphabet [Anum]{false,};
	bool CommonAlphabet [Anum]{false,};
	
	for(int i=0;i<s1.length();i++)
	{	s1Alphabet[s1[i]-'A']=true;	}
	
	for(int i=0;i<s2.length();i++)
	{	s2Alphabet[s2[i]-'A']=true;	}
	
	for(int i=0;i<Anum;i++)
	{	if(s1Alphabet[i]&&s2Alphabet[i]){	CommonAlphabet[i]=true;	}		}
	
		
	std::cout<<Find_LCS(s1 ,s2 ,CommonAlphabet ,0 ,std::make_pair(0,0));
	
	return 0;		
	
}

int Find_LCS(std::string& s1,std::string& s2,bool CommonAlphabet[],int count,Pair P )
{
	static int Count=0;
	
	if(s1.length()<s2.length())
	{
		return Find_LCS(s2,s1,CommonAlphabet, count, P);	
	}
	Count++;
	std::cout<<Count<<std::endl;
	
	if(count>=s2.length()||P.sd>=s1.length())
		{return P.fs;}
	
	if(CommonAlphabet[s2[count]-'A'])//s2의 count인덱스에 해당하는 글자가 s1에도 있을때
	{
		int i;
		for(i=P.sd;i<s1.length();i++)
		{
			if(s1[i]==s2[count])
				{	break;}
		}//s2의 count인덱스에 해당하는 글자가 s1탐색영역 안에 존재하면 i를 idx에 저장한다
		if(i<s1.length()-1)
		{	return std::max(Find_LCS(s1,s2,CommonAlphabet,count+1,std::make_pair(P.fs+1,i+1)),Find_LCS(s1,s2,CommonAlphabet,count+1,P));	}
		else
		{	return Find_LCS(s1,s2,CommonAlphabet,count+1,P);	}
		
	}
	else//s2의 count인덱스에 해당하는 글자가 s1에도 없을때
	{
		return Find_LCS(s1,s2,CommonAlphabet,count+1,P);
	}	
}