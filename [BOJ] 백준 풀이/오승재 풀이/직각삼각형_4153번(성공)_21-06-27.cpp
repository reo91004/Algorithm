#include <iostream>
using namespace std;

void swap(int&n1,int&n2)
{
	int temp=n1;
	n1=n2;
	n2=temp;
	return;	
}
bool IsRectangle(int side1,int side2,int side3)
{
	int s1,s2,s3;
	s1=side1;s2=side2;s3=side3;
	if(s2<s1)
	{swap(s1,s2);}
	if(s3<s1)
	{swap(s1,s3);}
	if(s3<s2)
	{swap(s3,s2);}
	
	
	if(s1*s1+s2*s2==s3*s3)
		return true;
	return false;
}

int main()
{
	int side1,side2,side3;
	while(1)
	{
		cin>>side1>>side2>>side3;
		if(side1==0&&side2==0&side3==0)
			break;
		if(IsRectangle(side1,side2,side3))
		{cout<<"right"<<'\n';}
		else
			cout<<"wrong"<<'\n';	
	}
	return 0;
}