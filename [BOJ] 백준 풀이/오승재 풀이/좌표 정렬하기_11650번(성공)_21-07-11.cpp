#include <iostream>
#include <algorithm>
using namespace std;


class point{
	
	private:
		int xpos;
		int ypos;
	public:
		point()
		{}
		point(int xpos,int ypos)
		:xpos(xpos), ypos(ypos)
		{}
		ostream& operator<<(ostream& os)
		{
			cout<<xpos<<' '<<ypos;	
			return os;
		}
		friend ostream& operator<<(ostream& os,const point p);
		friend bool compare(point p1,point p2);
	};
//class point

//friend function
	ostream& operator<<(ostream& os,const point p)
	{
		os<<p.xpos<<' '<<p.ypos;
		return os;	
	}
	bool compare(point p1,point p2)
	{
		if(p1.xpos==p2.xpos)
			{
				return p1.ypos<p2.ypos;
			}
		else
		{	
			return p1.xpos<p2.xpos;	
		}	
	}
//friend function
	
int main()
	{
		cout.sync_with_stdio(false);
		int len;
		cin>>len;
		point* arr=new point[len];
		
		for(int i=0;i<len;i++)
		{
				int xpos,ypos;
				cin>>xpos>>ypos;
				arr[i]=point(xpos,ypos);
		}
		sort(arr,arr+len,compare);
		
		for(int i=0;i<len;i++)
		{
			cout<<arr[i]<<'\n';	
		}
	}