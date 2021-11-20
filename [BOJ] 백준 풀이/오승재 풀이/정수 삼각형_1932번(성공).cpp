#include <iostream>

long long Maxpath(int* triangle, long long* newtriangle ,int n);

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
	int n;
	int *triangle;
	std::cin>>n;
	triangle=new int[n*(n+1)/2];
	
	for( int i=0;i<n*(n+1)/2;i++)
	{
		std::cin>>triangle[i];	
	}
	
	long long *newtriangle=new long long[n*(n+1)/2];
	
	std::cout<<Maxpath(triangle,newtriangle,n);
	delete []triangle;
	delete []newtriangle;
	
	return 0;
}

long long Maxpath(int* triangle, long long* newtriangle ,int n)
{
	newtriangle[0]=triangle[0];
	for(int N=2;N<=n;N++)
	{
		int prev=(N-1)*(N-2)/2;
		int pres=N*(N-1)/2;
		
		for(int k=0;k<N;k++)
		{
			if(k==0)
			{
				newtriangle[pres+k]=triangle[pres+k]+newtriangle[prev+k];
			}
			else if(k==N-1)
			{
				newtriangle[pres+k]=triangle[pres+k]+newtriangle[prev+k-1];
			}
			else
			{
				newtriangle[pres+k]=newtriangle[prev+k-1]>newtriangle[prev+k]?triangle[pres+k]+newtriangle[prev+k-1]:triangle[pres+k]+newtriangle[prev+k];
		    }
		}
		
	}
	int idx=n*(n-1)/2;
	long long max=newtriangle[idx++];
	while(idx<n*(n+1)/2)
	{
		if(max<newtriangle[idx])
			{
				max=newtriangle[idx];
			}
		idx++;
	}
	return max;
}