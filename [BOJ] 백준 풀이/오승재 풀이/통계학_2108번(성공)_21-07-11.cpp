#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int average=0,mode;	
		
	int *arr=new int[n];
	int Mode[8001]={0,};
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		arr[i]=num;
		Mode[num+4000]++;
		average+=num;
	}
	sort(arr,arr+n);
	
	int max=0;
	for(int i=0;i<8001;i++)
	{
		if(Mode[i]>max)
			max=Mode[i];
	}
	
	bool arr2[8001]={false,};
	int index=0;
	for(int i=0;i<8001;i++)
	{
			if(Mode[i]==max)
			 {arr2[i]=true;index++;}
	}
	if(index==1)
	{
		for(int i=0;i<8001;i++)
		{
			if(arr2[i]==true)
			{
				mode=i-4000;break;			
			}	
		}	
	}
	else
	{
		index=0;
		for(int i=0;i<8001;i++)
		{
			if(arr2[i]==true)
				index++;
			if(index==2)
				{mode=i-4000;break;}	
		}
	}
	double avg=average;
	avg/=n;
	if(avg>=0)
		avg+=0.5;
	else
		avg-=0.5;
	
	cout<<static_cast<int>(avg)<<'\n'<<arr[n/2]<<'\n'<<mode<<'\n'<<arr[n-1]-arr[0]<<endl;
	
	delete []arr;

	
	return 0;
}
