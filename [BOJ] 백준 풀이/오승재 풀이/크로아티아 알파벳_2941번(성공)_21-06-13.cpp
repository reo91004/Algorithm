#include<iostream>
#include<cstring>

using namespace std;
int Convert(const string str)
{
	int len=str.length();
	int count=0,index=0;
	while(index<=len-1)
	{
		string temp=str.substr(index,2);
		
		if(temp=="c="||temp=="c-"||temp=="d-"||temp=="lj"||temp=="nj"||temp=="s="||temp=="z=")
		{count++;index+=2;}
		else
		{
			temp=str.substr(index,3);
			if(temp=="dz=")
			{count++;index+=3;}
			else
			{index++;count++;}
			}
		}//while
		return count;
	}//Convert



int main()
{
	string str;
	cin>>str;
	cout<<Convert(str)<<endl;
	return 0;
	}
