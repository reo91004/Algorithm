#include <iostream>
#include <string>

void ImageCompressor(int** matrix,int X,int Y,int N);
int Check(int** matrix,int X,int Y,int N);
//White==0, Black==1
enum {White,Black};

int main()
{
	int N;
	std::cin>>N;
	
	int** matrix=new int* [N];
	
	for(int i=0;i<N;i++)
		matrix[i]=new int [N];
	//메모리 할당	
	for(int i=0;i<N;i++)
	{
		std::string s;
		std::cin>>s;
		for(int j=0;j<N;j++)
			matrix[i][j]=s[j]-'0';	
	}
			
		
	//Input Data
	ImageCompressor(matrix,0,0,N);
	
	
	for(int i=0;i<N;i++)
		delete [] matrix[i];
	delete []matrix;
	
	matrix=NULL;
	return 0;
}

void ImageCompressor(int** matrix,int X,int Y,int N)
{
	
	switch(Check(matrix,X,Y,N))
	{
		case White:
			std::cout<<White; break;
		case Black:
			std::cout<<Black; break;
		default:
			std::cout<<'(';
			for(int y=0;y<N;y+=N/2)
			{
				for(int x=0;x<N;x+=N/2)
					{ImageCompressor(matrix,X+x,Y+y,N/2);}	
			}
			std::cout<<')';
			break;
	}
	
	return ;
}



int Check(int**matrix,int X,int Y, int N)
{
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{
			if(matrix[Y][X]!=matrix[Y+y][X+x])	
				return -1;	
		}	
	}
	//std::cout<<"X Y N "<<X<<' '<<Y<<' '<<N<<"matrix[X][Y] "<<matrix[X][Y]<<'\n';
	return matrix[Y][X];
}