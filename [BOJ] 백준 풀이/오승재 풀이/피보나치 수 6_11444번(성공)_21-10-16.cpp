#include <iostream>
#define N 2
#define DIV 1000000007

long long* Power_Matrix(long long* matrix,long long B);
long long ShowValue(long long* matrix,long long n);

int main()
{
	long long n;
	std::cin>>n;
	
	long long matrix[N*N]={1,1,1,0};
	
	long long* ptr=Power_Matrix(matrix,n-1);
	
	std::cout<<ShowValue(ptr,n);
	
	delete []ptr;
	ptr=NULL;
	
	 return 0; 
}



long long* Power_Matrix(long long* matrix,long long B)
{
	long long* temp;
	if(B<=1)
	{
		temp= new long long[N*N];
		for(int i=0;i<N*N;i++)
			temp[i]=matrix[i];
		return temp;
	}	
	long long* Temp=new long long[N*N];
	
	temp=Power_Matrix(matrix,B/2);
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<N;x++)
		{	Temp[y*N+x]=0;
			for(int i=0;i<N;i++)
			{	Temp[y*N+x]+=temp[y*N+i]*temp[i*N+x]%DIV;	}	
			Temp[y*N+x]%=DIV;
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
				{	Temp[y*N+x]+=temp[y*N+i]*matrix[i*N+x]%DIV;	}	
			Temp[y*N+x]%=DIV;
			}	
		}			
	}
	
	delete []temp; temp=NULL; 
		return Temp;
}


long long ShowValue(long long* matrix,long long n)
{
	if(n==0)
		return 0;
	return (matrix[0])%DIV;	
}