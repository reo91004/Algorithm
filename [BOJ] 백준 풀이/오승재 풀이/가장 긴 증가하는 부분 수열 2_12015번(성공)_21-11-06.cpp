#include <iostream>
#include <vector>

int longest_partial_array(int arr[],int n);

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	
	int n;
	std::cin>>n;
	
	int* v=new int [n]();
	int vsize=1;	
	//v[i] i=수열의 길이 v[i]=해당 길이를 가지는 요소중 최소	
	
	for(int i=0;i<n;i++)
	{
		int num; std::cin>>num;
		if(v[vsize-1]<num)//vector 에다가 데이터를 추가 시키는 경우
		{
			v[vsize]=num; vsize++;	
		}
		else//해당 data로 vector를 개선시킬수 있는경우
		{
			int start=1;
			int end=vsize-1;
			int mid;
			while(end>=start)
			{
				mid=(start+end)/2;
				
				if(v[mid]<=num)
				{	start=mid+1;	}
				else if(v[mid-1]>=num)
				{	end=mid-1;	}
				else//v[mid-1]>num
				{	v[mid]=num;	}
			}	
		}
		
	}
	
	std::cout<<vsize-1;
	
	delete []v;
	
	return 0;		
	
}