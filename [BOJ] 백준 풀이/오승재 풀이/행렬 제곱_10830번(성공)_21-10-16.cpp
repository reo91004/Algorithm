#include <iostream>

int* Power_Matrix(int* matrix,int N,long long B);
void Show_Matrix(int* matrix,int N);

int main()
{
	int N;
	long long B;
	std::cin>>N>>B;
	
	int* matrix=new int[N*N];
	
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{int a;
			std::cin>>a; matrix[y*N+x]=a%1000;	
		}	
	}	
	
	int* temp=Power_Matrix(matrix,N,B);
	
	Show_Matrix(temp,N);
	
	delete []matrix; delete []temp;
	matrix=NULL; temp=NULL;
	
	return 0;
}



int* Power_Matrix(int* matrix,int N,long long B)
{
	int* temp;
	if(B==1)
	{
		temp= new int[N*N];
		for(int i=0;i<N*N;i++)
			temp[i]=matrix[i];
		return temp;
	}	
	int* Temp=new int[N*N];
	
	temp=Power_Matrix(matrix,N,B/2);
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{	Temp[y*N+x]=0;
			for(int i=0;i<N;i++)
			{	Temp[y*N+x]+=temp[y*N+i]*temp[i*N+x]%1000;	}	
			Temp[y*N+x]=Temp[y*N+x]%1000;
		}	
	}
	
	if(B%2==1)
	{
		for(int i=0;i<N*N;i++)
			temp[i]=Temp[i];
		
		for(int y=0;y<N;y++)
		{
			for(int x=0;x<N;x++)
			{	Temp[y*N+x]=0;
				for(int i=0;i<N;i++)
				{	Temp[y*N+x]+=temp[y*N+i]*matrix[i*N+x]%1000;	}	
			Temp[y*N+x]=Temp[y*N+x]%1000;
			}	
		}			
	}
	
	delete []temp; temp=NULL; 
		return Temp;
}

void Show_Matrix(int* matrix,int N)
{
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{
			std::cout<<matrix[y*N+x]<<' ';	
		}	
		std::cout<<'\n';
	}
	return;
}