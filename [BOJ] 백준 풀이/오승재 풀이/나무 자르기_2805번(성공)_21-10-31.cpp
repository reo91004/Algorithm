#include <iostream>
#include <algorithm>

int binary_length(int trees_length[],int n,long long m);
long long cuttedtrees_length(int trees_length[],int k,int length);


int main()
{
	 std::ios::sync_with_stdio(false),std::cin.tie(NULL);
	int n;
	long long m;
	//n is the number of tree, m is needed length of tree
	std::cin>>n>>m;
	
	int* trees_length=new int[n];
	for(int i=0;i<n;i++)
	{	std::cin>>trees_length[i];	}
	
	std::sort(trees_length,trees_length+n);
	
	std::cout<<binary_length(trees_length,n,m);	
			
	delete [] trees_length;
	
	return 0;	
}


int binary_length(int trees_length[],int n,long long m)
{
	unsigned int start=0;
	int end=trees_length[n-1];
	int mid;
	while(end>start)
	{
		mid=(start+end)/2;
		if(start==mid||end==mid)
			break;
			
		if(cuttedtrees_length(trees_length,n,mid)<m)//mid>answer
		{	end=mid-1;	}
		else//number_of_cuttedwirds()>=n //mid<=answer
		{	start=mid;	}
		//std::cout<<mid<<std::endl;	
	}
	if(cuttedtrees_length(trees_length,n,end)>=m)//start>answer
		return end;
	else
		return start;
}

long long cuttedtrees_length(int trees_length[],int n,int length)
{
	long long sum=0;
	for(int i=0;i<n;i++)
		{sum+=trees_length[i]-length>0 ? trees_length[i]-length : 0 ;}
	
	//std::cout<<"sum is :"<<sum<<std::endl;
	return sum;
}