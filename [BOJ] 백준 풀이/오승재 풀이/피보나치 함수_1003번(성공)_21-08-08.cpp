#include <iostream>

class node
{
	private:
		int c0;
		int c1;
	public:
		node():c0(0), c1(0)
		{}
		node(int c0,int c1):c0(c0), c1(c1)
		{}
		friend node operator+(const node& n1,const node& n2);
		friend std::ostream& operator<<(std::ostream& os, node n);
};

node operator+(const node& n1,const node& n2);
std::ostream& operator<<(std::ostream& os, node n);
void fibo(int n);


int main()
{
	int n;
	std::cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int N; std::cin>>N;
		fibo(N);	
	}
}

void fibo(int n)
{
	node memo[40];
	memo[0]=node(1,0); memo[1]=node(0,1);
	for(int i=2;i<=n;i++)
		memo[i]=memo[i-1]+memo[i-2];
	std::cout<<memo[n]<<'\n';
}

std::ostream& operator<<(std::ostream& os, node n)
{
	os<<n.c0<<' '<<n.c1; return os;	
}

node operator+(const node& n1,const node& n2)
{
	return node(n1.c0+n2.c0,n1.c1+n2.c1);	
}