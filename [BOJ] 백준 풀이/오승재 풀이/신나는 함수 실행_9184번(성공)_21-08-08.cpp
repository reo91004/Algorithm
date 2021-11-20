#include <iostream>
#define N 21

int w(int A,int B,int C);//input 0~20

int main()
{
	while(1)
	{
		int a,b,c;
		std::cin>>a>>b>>c;
		
		if(a==-1&&b==-1&&c==-1)
			return 0;
		std::cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<'\n';
	}
}


int w(int A,int B,int C)//input 0~20
{
	std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

	static int arr[N][N][N];//a=first, b=second, c=third 0~20;
	static bool first=true;
	if(first)
	{
	for(int a=0;a<N;a++)
	{
		for(int c=0;c<N;c++)
		{
			for(int b=0;b<N;b++)
			{
				if(a==0||b==0||c==0)
					arr[a][b][c]=1;
				else if(a<b&&b<c)
					arr[a][b][c]=arr[a][b][c-1]+arr[a][b-1][c-1]-arr[a][b-1][c];
				else
					arr[a][b][c]=arr[a-1][b][c]+arr[a-1][b-1][c]+arr[a-1][b][c-1]-arr[a-1][b-1][c-1];	
			}	
		}	
	}
	first=false;
	}
	if(A<=0||B<=0||C<=0)
		return 1;
	if(A>20||B>20||C>20)
		return arr[20][20][20];
	else
		return arr[A][B][C];
	}