#include <iostream>
#include <cstdlib>

class Team
{
	public:
		int* stack;
		int max;
		int num;
	public:
		Team(int N):max(N),num(0)
		{ stack=new int[N];}	
		void Push (int n)
		{ stack[num++]=n;}
		int Pop()
		{ return stack[--num];}
		int Sum(int **matrix);
		~Team()
		{ delete []stack;	}
};

int Calculate(int** matrix,int N,bool Arr[],int idx);
void InputData(int** matrix, int N);
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
	int N;
	std::cin>>N;
	int** matrix=new int*[N];
	for(int i=0;i<N;i++)
		matrix[i]=new int[N];
		
	InputData(matrix,N);
	
	bool* Arr=new bool[N];
	for(int i=0;i<N;i++)
		Arr[i]=true;
	
	std::cout<<Calculate(matrix,N,Arr,0);
	
	for(int i=0;i<N;i++)
		delete [] matrix[i];
	delete [] matrix;
	
	return 0;
}// int main()

void InputData(int** matrix, int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			std::cin>>matrix[i][j];
		}	
	}
}//void InputData()

int Team::Sum(int **matrix)
{
	int sum=0;
	for(int i=0;i<max;i++)
		{
			for(int j=0;j<max;j++)
			{
				sum+=matrix[stack[i]][stack[j]];	
			}
		}
	return sum;
}// int Team::Sum

int Calculate(int** matrix,int N,bool Arr[],int idx)
{
	static int min=100;
	static bool first=true;
	static Team T1(N/2);

	if(idx>=N/2)
	{
		int sum1, sum2;
		Team T2(N/2);
		for(int i=0;i<N;i++)
			if(Arr[i])
				T2.Push(i);
				
		sum1=T1.Sum(matrix); sum2=T2.Sum(matrix);
	 if(min>abs(sum1-sum2)||first)
		{
			min=abs(sum1-sum2);first=false;	
		}
		return 0;
	}//if(idx>=N/2)
	
	switch(idx)
	{	
	case 0:
		for(int i=0;i<N;i++)
		{
			if(Arr[i])
			{
				Arr[i]=false; T1.Push(i);
				Calculate(matrix,N,Arr,idx+1);
				Arr[i]=true; T1.Pop();	
			}	
		}
		break;
		
	default:
		for(int i=T1.stack[T1.num-1];i<N;i++)
		{
			if(Arr[i])
			{
				Arr[i]=false; T1.Push(i);
				Calculate(matrix,N,Arr,idx+1);
				Arr[i]=true; T1.Pop();	
			}	
		}
	}//switch(idx)
	return min;
}//void calculator