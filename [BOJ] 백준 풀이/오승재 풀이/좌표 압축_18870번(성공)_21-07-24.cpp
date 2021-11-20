#include <iostream>
#include <algorithm>

class Newpoint;
class point
{
	private:
		int pos;
		Newpoint* ptr;
	public:
		point()
		{}
		point(int pos,Newpoint* ptr)
		:pos(pos), ptr(ptr)
		{}	
		Newpoint* Getptr()
		{return ptr;}
		const int Getpos()
		{return pos;}
		friend int compare(point&p1,point&p2);
		friend std::ostream& operator<<(std::ostream&os,point p);
};

std::ostream& operator<<(std::ostream&os,point p)
{
	std::cout<<p.pos;	
	return os;
}

class Newpoint
{
	private:
		int npos;
	public:
		Newpoint()
		{}
		Newpoint(int npos):npos(npos)
		{}
	friend std::ostream& operator<<(std::ostream&os,Newpoint p);
};

std::ostream& operator<<(std::ostream&os,Newpoint p)
{
	std::cout<<p.npos;
	return os;	
}

int compare(point&p1,point&p2)
{
	return p1.pos<p2.pos;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int num;
	std::cin>>num;
	point* parr=new point[num];
	Newpoint* Nparr=new Newpoint[num];
	for(int i=0;i<num;i++)
	{
		int p; std::cin>>p;
		parr[i]=point(p,Nparr+i);
	}
	//sort
	std::sort(parr,parr+num,compare);
	
	//npos할당
	int npos=0;
	*parr[0].Getptr()=Newpoint(npos);
	for(int i=1;i<num;i++)
	{
		if(parr[i].Getpos()==parr[i-1].Getpos())
				*parr[i].Getptr()=Newpoint(npos);
		else
		 	*parr[i].Getptr()=Newpoint(++npos);
	}
	
	//출력
	for(int i=0;i<num;i++)
	{
		std::cout<<Nparr[i]<<' ';	
	}
	delete []parr;
	delete []Nparr;
	
	return 0;
}