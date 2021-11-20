#include <iostream>
#include <cmath>
using namespace std;

class point
{
	private:
		int x;
		int y;
		int length;
	public:
		point(int x,int y, int length)
		:x(x), y(y), length(length)
		{}
		int GetX()
		{return x;}
		int GetY()
		{return y;}
		int GetLength()
		{return length;}
};

double Length(int x,int y)
{
	return sqrt (x*x+y*y);
}

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int x,y,length;
		cin>>x>>y>>length;
		point Jo(x,y,length);	
		cin>>x>>y>>length;
		point Baek(x,y,length);
		double L;
		L=Length(Jo.GetX()-Baek.GetX(),Jo.GetY()-Baek.GetY());
		int Short=Jo.GetLength(); int Long=Baek.GetLength();
		if(Short>Long)
		{
			int temp=Short;
			Short=Long;
			Long=temp;	
		} 
		
		if(Jo.GetX()==Baek.GetX()&&Jo.GetY()==Baek.GetY()&&Jo.GetLength()==Baek.GetLength())
		{
			cout<<-1<<endl;
		}
		else if(L>Short+Long||Long>L+Short)
		{
			cout<<0<<endl;
		} 
		else if(L==Short+Long||Long==L+Short)
		{
			cout<<1<<endl;	
		}
		else
		{
			cout<<2<<endl;	
		}
	}
}