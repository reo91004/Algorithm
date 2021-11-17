#include <iostream>
#include <queue>
#include <functional>


void swap(int& a,int& b);
void push_data_leftheap(int heap[],int&heap_len,int num);
void push_data_rightheap(int heap[],int&heap_len,int num);
int pop_data_leftheap(int heap[],int&heap_len);
int pop_data_rightheap(int heap[],int&heap_len);
void correction_both_heap(int left_heap[],int right_heap[],int& leftlen,int& rightlen);
void print_heap(int heap[],int heaplen);

int main()
{
    std::ios::sync_with_stdio(false),std::cin.tie(NULL);

    int n;
    std::cin>>n;
	
	int leftlen=0,rightlen=0;
	
	int* left_heap=new int [n+1]();	
	int* right_heap=new int [n+1]();
	
	std::make_heap(left_heap,left_heap+n+1,std::less<int>());//내림차순	
	std::make_heap(right_heap,right_heap+n+1,std::greater<int>());//오름차순
	
	for(int i=0;i<n;i++)
	{
	 	int num; std::cin>>num;
	 	if(i==0)
	 	{
	 		push_data_leftheap(left_heap,leftlen,num);
	 	}
	 	else if(i==1)
	 	{
	 		push_data_rightheap(right_heap,rightlen,num);
	 		if(left_heap[0]>right_heap[0])
	 			swap(left_heap[0],right_heap[0]);	
	 	}
	 	else
	 	{
	 		if(num<=right_heap[0])
	 		{
	 			push_data_leftheap(left_heap,leftlen,num);
	 		}
	 		else// (num>right_heap[0])
	 		{
	 			push_data_rightheap(right_heap,rightlen,num);	
	 		}
	 	}
	 	//Input Data
	 	correction_both_heap(left_heap,right_heap,leftlen,rightlen);
	 	//보정 구간
	 //	print_heap(left_heap,leftlen);print_heap(right_heap,rightlen);
	 //	std::cout<<"i is a"<<i<<std::endl;
	 	std::cout<<left_heap[0]<<'\n';
	 	//print middle_value
	 }
 
    delete [] left_heap;
    delete [] right_heap;

    return 0;
}


void swap(int& a,int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

void push_data_leftheap(int heap[],int&heap_len,int num)
{
	heap[heap_len++]=num;
	std::push_heap(heap,heap+heap_len,std::less<int>());
}

void push_data_rightheap(int heap[],int&heap_len,int num)
{
	heap[heap_len++]=num;
	std::push_heap(heap,heap+heap_len,std::greater<int>());
}


int pop_data_leftheap(int heap[],int&heap_len)
{
	std::pop_heap(heap,heap+heap_len,std::less<int>());
	return heap[--heap_len];
}

int pop_data_rightheap(int heap[],int&heap_len)
{
	std::pop_heap(heap,heap+heap_len,std::greater<int>());
	return heap[--heap_len];
}

void correction_both_heap(int left_heap[],int right_heap[],int& leftlen,int& rightlen)
{
	if(leftlen-rightlen>=2)
	{
		push_data_rightheap(right_heap,rightlen,pop_data_leftheap(left_heap,leftlen));
	}
	else if(rightlen-leftlen>=1)
	{
		push_data_leftheap(left_heap,leftlen,pop_data_rightheap(right_heap,rightlen));
	}
}

void print_heap(int heap[],int heaplen)
{
	for(int i=0;i<heaplen;i++)
	{
		std::cout<<heap[i]<<std::endl;	
	}
	std::cout<<std::endl;
}