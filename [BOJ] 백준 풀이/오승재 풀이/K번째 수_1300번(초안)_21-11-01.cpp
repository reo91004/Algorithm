#include <iostream>
#include<cmath>
#include<algorithm>

int Binary_serach(int n,int k);
int index_of_number(int n,int num);
int count_the_number_of_num(int n,int num);


int main()
{
	int n,k;
	std::cin>>n>>k;
	
	std::cout<<Binary_serach(n,k);
	
	
	return 0;						
}


int Binary_serach(int n,int k)
{
	int start=1;
	int end=std::min(std::pow(n,2),std::pow(10,9));
	int mid;
	while(end>=start)
	{
		mid=(start+end)/2;
		int idx=index_of_number(n,mid);
		//std::cout<<"mid, idx "<<mid<<" "<<idx<<std::endl;
		if(idx>=k)
		{
			int number_of_mid=count_the_number_of_num(n,mid);
			if(idx-number_of_mid+1<=k)
			{	break;	}
			end=mid-1;
		}
		else
		{
			start=mid+1;	
		}	
	}
	return mid;
}

int index_of_number(int n,int num)
{
	int index=0;
	for(int i=1;i<=n;i++)
	{
		index+=std::min(num/i,n);	
	}
	return index;
}

int count_the_number_of_num(int n,int num)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(num%i==0&&num/i<=n)
			count++;	
	}
	return count;
}