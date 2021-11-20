#include <iostream>
using namespace std;

int chess(char**,int,int);
int checker(char [8][8]);
int main()
{
	int col,row;
	cin>>col>>row;
	char** matrix=new char*[col];
	for(int i=0;i<col;i++)
	{
		matrix[i]=new char[row];	
	}	
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			char c; cin>>c;
			matrix[i][j]=c;
		}	
	}
	cout<<chess(matrix,col,row)<<endl;
	
	for(int i=0;i<col;i++)
	{delete []matrix[i];}
	delete []matrix;
}

int chess(char** matrix,int col,int row)
{
	int min=63;
	for(int i=0;i<col-7;i++)
	{
		for(int j=0;j<row-7;j++)
		{
			char Matrix[8][8];
			for(int a=0;a<8;a++)
			{
				for(int b=0;b<8;b++)
				{
					Matrix[a][b]=matrix[i+a][j+b];	
				}	
			}
			int num=checker(Matrix);
			if(min>num)
				min=num;
		}	
	}
	return min;
}

int checker(char matrix[8][8])
{
	int count=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i==0&&j==0)
			{continue;}
			else if(j==0)
			{
				if(matrix[i][j]==matrix[i-1][j])
				{	
					count++;
					if(matrix[i][j]=='B')
						matrix[i][j]='W';
					else
						matrix[i][j]='B';
				}
			}
			else 
			{
				if(matrix[i][j]==matrix[i][j-1])
				{	
					count++;
					if(matrix[i][j]=='B')
						matrix[i][j]='W';
					else
						matrix[i][j]='B';
				}
			}
		}	
	}
	if(count>32)
	{count-=64;count*=-1;}
	return count;
}