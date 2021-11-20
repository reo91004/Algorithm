#include<iostream>
#include<cstring>
using namespace std;


bool Group_Word_Checker(const string str)
{
	int check[26]={0,};
	char c=str.at(0);
	check[c-'a']++;
	for(int i=1;i<str.length();i++)
	{	
		char temp=c;
		c=str.at(i);
		if(temp==c)
		{continue;}
		//temp!=c
		if(check[c-'a']!=0)//두번나옴;
			return false;
		else//해당철자가 처음나옴
		{
			check[c-'a']++;
			}
		}
		return true;
	}
	
	int main()
	{
		int num;
		cin>>num;
		int count=0;
		for(int i=0;i<num;i++)
		{
			string str;
			cin>>str;
			if(Group_Word_Checker(str))
				count++;
			}
		cout<<count<<endl;
		}