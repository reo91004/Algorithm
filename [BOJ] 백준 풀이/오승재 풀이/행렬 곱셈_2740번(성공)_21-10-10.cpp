#include <iostream>


int** MulMatrix(int** A,int **B,int N,int M,int K);
void PrintMatrix(int** Matrix,int X,int Y);


int main()
{
	int N,M,K;
	
	//A
	std::cin>>N>>M;
	
	int**A= new int* [N];
	for(int i=0;i<N;i++)
		A[i]=new int [M];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			std::cin>>A[i][j];	
	//A
	
	//B
	std::cin>>M>>K;
	
	int**B= new int* [M];
	for(int i=0;i<M;i++)
		B[i]=new int [K];
	
	for(int i=0;i<M;i++)
		for(int j=0;j<K;j++)
			std::cin>>B[i][j];	
	//B
	
	int** Matrix=MulMatrix(A,B,N,M,K);
	PrintMatrix(Matrix,K,N);
	
	
	//Delocate
		for(int i=0;i<N;i++)
			delete []A[i];
		delete []A;
		
		for(int i=0;i<M;i++)
			delete []B[i];
		delete []B;
		
		for(int i=0;i<N;i++)
			delete []Matrix[i];
		delete []Matrix;
	
		A=NULL; B=NULL; Matrix=NULL;
		
		return 0;
}

int** MulMatrix(int** A,int **B,int N,int M,int K)
{
	int** Temp=new int* [N];
	for(int i=0;i<N;i++)
		Temp[i]=new int [K];
		
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<K;x++)
		{
			Temp[y][x]=0;
			for(int i=0;i<M;i++)
			{
				Temp[y][x]+=A[y][i]*B[i][x];	
			}	
		}	
	}
	
	return Temp;
}

void PrintMatrix(int** Matrix,int X,int Y)
{
	for(int y=0;y<Y;y++)
	{
		for(int x=0;x<X;x++)
		{
			std::cout<<Matrix[y][x]<<' ';	
		}
		std::cout<<'\n';	
	}
}