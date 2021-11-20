/*
구글 보고 참고 자료보고 맞춤 다음엔 이러지말고 더 좋은 생각 해보기
*/

#include <iostream>
#include <numeric>

int Find_2(int n);
int Find_5(int n);

int main()
{
	int N, M;
	int Count_2=0, Count_5=0;
	
	std::cin>>N>>M;
	
	Count_2+=Find_2(N);
	Count_2-=Find_2(M);
	Count_2-=Find_2(N-M);
	
	Count_5+=Find_5(N);
	Count_5-=Find_5(M);
	Count_5-=Find_5(N-M);
	
	std::cout<<std::min(Count_2,Count_5);
	
	return 0;				
}


int Find_2(int n)
{
	int C2=0;
	while(n>0)
	{
		C2+=n/2;
		n/=2;	
	}
	return C2;
}
int Find_5(int n)
{
	int C5=0;
	while(n>0)
	{
		C5+=n/5;
		n/=5;	
	}
	return C5;
}