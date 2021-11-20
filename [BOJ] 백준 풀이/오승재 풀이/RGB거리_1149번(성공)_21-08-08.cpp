#include <iostream>

enum {R=0,G,B};

class House
{
	private:
		int color[3];
	public:
		House(int r=0,int g=0,int b=0)
		{color[R]=r; color[G]=g; color[B]=b;}
		int Getvalue(int sw) const
		{return color[sw];}		
};


int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N;
	std::cin>>N;
	
	House* Old= new House[N];
	House* New= new House[N];
	for(int i=0;i<N;i++)
	{
		int r,g,b;
		std::cin>>r>>g>>b;
		Old[i]=House(r,g,b);		
	}	
	New[0]=Old[0];

	for(int i=1;i<N;i++)
	{
		int r,g,b;
		//R	
		r= New[i-1].Getvalue(G)<New[i-1].Getvalue(B)? New[i-1].Getvalue(G)+Old[i].Getvalue(R): New[i-1].Getvalue(B)+Old[i].Getvalue(R);
		//G
		g= New[i-1].Getvalue(R)<New[i-1].Getvalue(B)? New[i-1].Getvalue(R)+Old[i].Getvalue(G): New[i-1].Getvalue(B)+Old[i].Getvalue(G);
		//B
		b= New[i-1].Getvalue(R)<New[i-1].Getvalue(G)? New[i-1].Getvalue(R)+Old[i].Getvalue(B): New[i-1].Getvalue(G)+Old[i].Getvalue(B);
		New[i]=House(r,g,b);
	}
	int min=New[N-1].Getvalue(R);
	if(min>New[N-1].Getvalue(G))
		min=New[N-1].Getvalue(G);
	if(min>New[N-1].Getvalue(B))
		min=New[N-1].Getvalue(B);
	
	std::cout<<min;
	delete []Old;
	delete []New;	
	return 0;
}