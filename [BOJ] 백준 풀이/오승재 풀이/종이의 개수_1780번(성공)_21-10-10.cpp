#include <iostream>
#include <tuple>

class Tri{
 	public:
 		int n1;
 		int n2;
 		int n3;
 	Tri(int n1,int n2,int n3):n1(n1), n2(n2), n3(n3)
 	{}
 	void Plus(Tri Temp);
 	void Print() const;
 };
 
Tri NumberOfPaper( int**matrix,int X,int Y,int N);
int Check(int**matrix,int X,int Y,int N) ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin>>N;
	
	int** matrix= new int* [N];
	for(int i=0;i<N;i++)
		matrix[i]=new int [N];	
	//Allocate Memory
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)	
			std::cin>>matrix[y][x];	
	}	

	//Input Data
	Tri Papers=NumberOfPaper(matrix,0,0,N);
	
	Papers.Print();
	
	for(int i=0;i<N;i++)
		delete [] matrix[i];
	delete []matrix;
	
	matrix=NULL;
	
	return 0;
}


Tri NumberOfPaper(int**matrix,int X,int Y,int N)
{
	Tri Papers(0,0,0);
	switch(Check(matrix,X,Y,N))
	{
		case -1:
			Papers.Plus(Tri(1,0,0));	break;
		case 0:
			Papers.Plus(Tri(0,1,0));	break;
		 case 1:
			Papers.Plus(Tri(0,0,1));	break;
		 default:
		 	for(int y=0;y<N;y+=N/3)
		 	{
		 		for(int x=0;x<N;x+=N/3)
		 			Papers.Plus(NumberOfPaper(matrix,X+x,Y+y,N/3));	
		 	}
		 	break;
	}
	return Papers;
}

void PrintTriple(std::tuple<int,int,int> Triple)
{
	std::cout<<std::get<0>(Triple)<<'\n';
	std::cout<<std::get<1>(Triple)<<'\n';
	std::cout<<std::get<2>(Triple)<<'\n';
	return ;
}

int Check(int**matrix,int X,int Y,int N)
{
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{
			if(matrix[Y][X]!=matrix[Y+y][X+x])
				return -2;	
		}		
	}
	return matrix[Y][X];	
}

void Tri::Plus(Tri Temp)
{
	n1+=Temp.n1; n2+=Temp.n2; n3+=Temp.n3;	
}

void Tri::Print() const
{
	std::cout<<n1<<'\n';
	std::cout<<n2<<'\n';
	std::cout<<n3<<'\n';	
}