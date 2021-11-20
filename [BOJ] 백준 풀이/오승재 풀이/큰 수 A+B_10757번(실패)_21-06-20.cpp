#include <iostream>
#include <cstring>
using namespace std;

char* Add(int* a,int alen, int* b,int blen);

int main()
{
	string sa,sb;
	cin>>sa>>sb;
	int alen=sa.length(),blen=sb.length();
    int* a=new int[alen],*b=new int[blen];
    char* str;
    
    for(int i=0;i<alen;i++)
    {
    	a[i]=sa[(alen-1)-i]-'0'; 
       }
    for(int i=0;i<blen;i++)
    {
    	b[i]=sb[(blen-1)-i]-'0';	
    }
    if(alen>=blen)
    {
    	str=Add(a,alen,b,blen);
    }	
    else
    {
    	str=Add(b,blen,a,alen);	
    }
    cout<<str<<endl;
    delete str;
    delete a;delete b;
}

char* Add(int *a, int alen, int *b, int blen)
{
	char* str=new char[alen+1];
	int* Sum=new int[alen+1];

	for(int i=0;i<alen;i++)
	{
		Sum[i]+=a[i]+b[i];
		if(Sum[i]>=10)
		{Sum[i+1]++;Sum[i]-=10;}
	}
	
	for(int i=0;i<=alen;i++)
	{
		if(Sum[i]>=10)
		{Sum[i+1]++;Sum[i]-=10;}
	}
	
	if(Sum[alen]==0)
	{
		for(int i=alen-1;i>=0;i--)
		{//cout<<Sum[i];
		str[i]=Sum[(alen-1-i)]+'0';
		}
	}
	else
	{
		{
		for(int i=alen;i>=0;i--)
		{//cout<<Sum[i];
		str[i]=Sum[(alen-i)]+'0';
		}
	}	
	}
	delete Sum;
	return str;
}