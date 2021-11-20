#include <iostream>
#include <deque>

int FindNum(std::deque <int>& DQ,int Num);
void MoveLeft(std::deque <int>& DQ);
void MoveRight(std::deque <int>& DQ);
void Pop(std::deque <int>& DQ);
int main()
{
	int N,M;//N=큐의 크기, M=뽑아내려고 하는 수의 개수
	std::cin>>N>>M;
	
	std::deque <int> DQ;
	for(int i=1;i<=N;i++)
		DQ.push_back(i);
	
	int* Sequence= new int[M];
	
	for(int i=0;i<M;i++)
		std::cin>>Sequence[i];
	//Input Sequence
	
	int count=0;
	
	 for(int i=0;i<M;i++)
	 {
	 	int idx=FindNum(DQ,Sequence[i])+1;
	 	if(idx<=DQ.size()/2+1)//앞에서 빼는게 이득임
	 	{
	 		for(int j=0;j<idx-1;j++)
	 			{MoveLeft(DQ);count++;}
	 		Pop(DQ);
	 	}
	 	else//idx>DQ.size()/2+1 //뒤에서 빼는게 이득
	 	{
	 		for(int j=idx;j<=DQ.size();j++)
	 			{MoveRight(DQ);count++;}
	 		Pop(DQ);
	 	}
	 } 
	
	std::cout<<count;
	
	delete []Sequence; Sequence=NULL;
	return 0;
}

int FindNum(std::deque <int>& DQ,int Num)
{
	for(int i=0;i<DQ.size();i++)
		if(DQ[i]==Num)
			{	return i;	}
	
}

void MoveLeft(std::deque <int>& DQ)
{
	DQ.push_back(DQ.front()); DQ.pop_front();
	//std::cout<<"MoveLeft"<<std::endl;	
}

void MoveRight(std::deque <int>& DQ)
{
	DQ.push_front(DQ.back()); DQ.pop_back();
	//std::cout<<"MoveRight"<<std::endl;
}
void Pop(std::deque <int>& DQ)
{
	DQ.pop_front();	
}