/* 좀 더 좋은 해결책이 존재 할것같음 또 같은 연산을 꼭 2번 할 이유는 없음*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Move(int num,int x,int y)//x는 출발 y는 목표
{
	if(num>1)
		Move(num-1,x,6-y-x);
	cout<<x<<' '<<y<<'\n';
	if(num>1)
		Move(num-1,6-y-x,y);
}
int Movenum(int num,int x,int y)//x는 출발 y는 목표
{
	static int i=0;
	if(num>1)
		Movenum(num-1,x,6-y-x);
		i++;
	if(num>1)
		Movenum(num-1,6-y-x,y);
	return i;
}


int main()
{
	int num;
	cin>>num;
	int i=Movenum(num,1,3);
	cout<<i<<'\n';
	Move(num,1,3);
	return 0;
}
