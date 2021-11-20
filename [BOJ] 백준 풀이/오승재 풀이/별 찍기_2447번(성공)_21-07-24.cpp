#include <iostream>


void Star(char** temp,int n,int X,int Y)
{
	if(n>3)
	{
		for(int y=0;y<n;y+=n/3)
		{
			for(int x=0;x<n;x+=n/3)
			{
				Star(temp,n/3,X+x,Y+y);	
			}	
		}	
	}
	for(int i=n/3;i<2*n/3;i++)
	{
		for(int j=n/3;j<2*n/3;j++)
		{
			temp[i+Y][j+X]=' ';	
		}
	}
		
}


int main()
{
	int n;
	std::cin>>n;
	char**star=new char*[n];
	for(int i=0;i<n;i++)
		star[i]=new char [n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			star[i][j]='*';	
		}	
	}
	
	
	
	Star(star,n,0,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{std::cout<<star[i][j];}	
	std::cout<<'\n';
	}
	
	for(int i=0;i<n;i++)
		delete [] star[i];
	delete []star;
	return 0;
}