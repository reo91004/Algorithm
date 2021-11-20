#include <iostream>
#include <algorithm>
using namespace std;

class point
{
	private:
		int pos;
		int sequence;
		int newpos;	
	public:
		point()
		{}
		point(int pos,int sequence)
		:pos(pos), sequence(sequence)
		{}
		void Setnewpos(int newpos)
		{this->newpos=newpos;}
		int Getpos()const
		{return pos;}
		int Getsequence ()const
		{return sequence;}
		int Getnewpos()const
		{return newpos;}
		friend bool compare(point&,point&);
};
bool compare(point&p1,point&p2)
{
	return p1.pos<p2.pos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	point* arr=new point[n];
	
	for(int i=0;i<n;i++)
	{
		int pos;cin>>pos;
		arr[i]=point(pos,i);	
	}
	sort(arr,arr+n,compare);
	int newpos=0;
	arr[0].Setnewpos(newpos);
	for(int i=1;i<n;i++)
	{
		if(arr[i-1].Getpos()==arr[i].Getpos())
			arr[i].Setnewpos(newpos);
		else
			arr[i].Setnewpos(++newpos);	
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j].Getsequence()==i)
			{cout<<arr[j].Getnewpos()<<' ';break;}	
		}	
	}
		delete []arr;
		return 0;
}

