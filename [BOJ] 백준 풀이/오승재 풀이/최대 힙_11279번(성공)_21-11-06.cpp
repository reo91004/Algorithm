#include <iostream>

inline void swap(int& n1,int &n2);
void input_data(int arr[],int& arrlen,int num);
void resort_heap(int arr[],int arrlen);

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	
	int n;
	std::cin>>n;
	
	int* arr=new int [n]();
	int arrlen=0;
	
	for(int i=0;i<n;i++)
	{
		int num; std::cin>>num;
		
		if(num==0)
		{
			if(arrlen<=0)
			{	std::cout<<"0\n"; arrlen=0;	}
			else
			{
				std::cout<<arr[0]<<'\n'; arr[0]=arr[--arrlen];
				arr[arrlen]=0;
				resort_heap(arr,arrlen);
				//힙의 최댓값을 가장 위로 옮김	
			}	
		}
		else
		{	input_data(arr,arrlen,num);	}	
	}
	
	delete [] arr;
	
	return 0;
}

inline void swap(int& n1,int &n2)
{
	int temp=n1;
	n1=n2;
	n2=temp;	
}

void input_data(int arr[],int& arrlen,int num)
{
	arr[arrlen++]=num;
	int idx=arrlen-1;
	
	while(idx>0&&arr[idx]>arr[(idx-1)/2])
	{	swap(arr[idx],arr[(idx-1)/2]); idx=(idx-1)/2;	}	
}

void resort_heap(int arr[],int arrlen)
{
	int idx=0;

	while(arrlen>idx*2)
	{
		int left=idx*2+1< arrlen ? idx*2+1 : arrlen;
		int right=idx*2+2< arrlen ? idx*2+2 : arrlen;
		//arr[arrlen]==0
		bool left_is_bigger= arr[idx]<arr[left];
		bool right_is_bigger=arr[idx]<arr[right];
		
		if(left_is_bigger&&right_is_bigger)
		{
			if(arr[left]>arr[right])
			{	swap(arr[idx],arr[left]); idx=left;	}
			else
			{	swap(arr[idx],arr[right]); idx=right;	}
		}
		else if(left_is_bigger)
		{	swap(arr[idx],arr[left]); idx=left;	}
		else if(right_is_bigger)
		{	swap(arr[idx],arr[right]); idx=right;	}
		else
		{	break;	}	
	}
	
}