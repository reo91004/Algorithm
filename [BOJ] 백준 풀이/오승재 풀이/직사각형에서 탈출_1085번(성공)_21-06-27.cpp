#include<iostream>
using namespace std;

class point
{
	private:
		int x;
		int y;
	public:
		point(int x,int y)
		:x(x), y(y)
		{}
		int GetX()const
		{return x;}
		int GetY()const
		{return y;}
};

int main()
{
	int x,y,w,h;
	cin>>x>>y>>w>>h;
	point leftdown(0,0);
	point hansu(x,y);
	point rightup(w,h);
	
	int length[4];
	length[0]=hansu.GetX()-leftdown.GetX(); length[1]=rightup.GetX()-hansu.GetX();
	length[2]=hansu.GetY()-leftdown.GetY(); length[3]=rightup.GetY()-hansu.GetY();
	int min=length[0];
	for(int i=1;i<4;i++)
	{
		if(min>length[i])
			min=length[i];
	}
	cout<<min<<endl;
	return 0;
}