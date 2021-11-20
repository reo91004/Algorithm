#include <iostream>
#include <utility>

std::pair<int,int> FindWnB(int**matrix,int X,int Y,int N);//처음은 White, 두번째는 Blue
int Check(int**matrix,int X,int Y, int N);//영역의 모든 색이 똑같으면 return true 아니면 return false


enum{White,Blue};

int main()
{
	int N;
	std::cin>>N;
	
	int** matrix=new int* [N];
	for(int i=0;i<N;i++)
		matrix[i]= new int [N];
		
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			std::cin>>matrix[i][j];	
	}
	std::pair<int,int> WnB=FindWnB(matrix,0,0,N);
	
	std::cout<<WnB.first<<'\n'<<WnB.second<<'\n';
	
	for(int i=0;i<N;i++)
		delete [] matrix[i];
	delete [] matrix;
	
	
	return 0;
}

std::pair<int,int> FindWnB(int**matrix,int X,int Y,int N)
{
	std::pair<int,int> temp(0,0);
	switch(Check(matrix,X,Y,N))
	{
		case White:
			temp.first++;
			break;
		case Blue:
			temp.second++;
			break;
		default:
			for(int y=0;y<N;y+=N/2)
			{
				for(int x=0;x<N;x+=N/2)
				{
					std::pair<int,int>temp2=FindWnB(matrix,X+x,Y+y,N/2);
					temp.first+=temp2.first; temp.second+=temp2.second; 	
				}	
			}
			break;
		
				
	}
	
	return temp;
}

int Check(int**matrix,int X,int Y, int N)
{
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{
			if(matrix[X][Y]!=matrix[X+x][Y+y])	
				return -1;	
		}	
	}
	//std::cout<<"X Y N "<<X<<' '<<Y<<' '<<N<<"matrix[X][Y] "<<matrix[X][Y]<<'\n';
	return matrix[X][Y];
}