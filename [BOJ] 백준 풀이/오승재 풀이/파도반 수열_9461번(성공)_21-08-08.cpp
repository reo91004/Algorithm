#include <iostream>

long long Padovan(int n)
{
	static long long int arr[100];
	static bool first=true;
	arr[0]=arr[1]=arr[2]=1; arr[3]=arr[4]=2; arr[5]=3;
	arr[6]=4;arr[7]=5;arr[8]=7;arr[9]=9;
	
	if(first)
	{
		for(int i=10;i<100;i++)
		{
			arr[i]=arr[i-1]+arr[i-5];	
		}
		first=false;
	}
	return arr[n-1];
}


int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int t;
	std::cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int n; std::cin>>n;
		std::cout<<Padovan(n)<<'\n';	
	}
	return 0;
}