#include <iostream>
#include <cstdlib>
#include <cstring>
#define STRLEN 10002

void reverse(char* s,int len)
{
	for(int i=0;i<len/2;i++)
	{
		char temp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=temp;	
	}	
}
char* Plus(char L[],char S[],int Long,int Short)
{
	char* temp=new char[Long+2];
	int i=0;
	int next=0;
	for(i;i<Short;i++)
	{
		int a=L[i]-'0';
		int b=S[i]-'0';
		int c=a+b+next;next=0;
		while(c>=10)
		{c-=10;next++;}
		temp[i]=c+'0';	
	}//문자열 S가 있는 곳까지 덧셈을 진행함
	
	while(i<Long)
	{
		int a=L[i]-'0';
		int c=a+next;next=0;
		while(c>=10)
		{c-=10;next++;}	
		temp[i]=c+'0';
		i++;
	}//문자열 L이 있는곳 까지 덧셈을 진행함
	
	while(next)
	{temp[i++]=next+'0';next=0;}
	std::cout<<i<<std::endl;
	temp[i]='\0';
	return temp;
}
int main()
{
	char s1[STRLEN]={0,};
	char s2[STRLEN]={0,};
	std::cin>>s1>>s2;
	int slen1=strlen(s1), slen2=strlen(s2);
	reverse(s1,slen1);	reverse(s2,slen2);
	char* s3;
	if(slen1>=slen2)
		s3=Plus(s1,s2,slen1,slen2);
	else
		s3=Plus(s2,s1,slen2,slen1);
	int slen3=strlen(s3);
	reverse(s3,slen3);
		std::cout<<s3<<std::endl;
	delete []s3;
	return 0;	
}