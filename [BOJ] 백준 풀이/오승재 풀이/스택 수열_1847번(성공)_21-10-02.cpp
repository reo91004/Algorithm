#include <iostream>
#include <stack>
#include <vector>

void StackMacker(int* arr,int n);

int main()
{	
	int n;
	std::cin>>n;
	
	int* arr=new int [n];
	for(int i=0;i<n;i++)
		std::cin>>arr[i];
		
	 StackMacker(arr,n);
	
	delete []arr;
	arr=NULL;
		
	return 0;
}

void StackMacker(int* arr,int n)
{
	int idx=0;
	int num=1;
	
	std::stack <int> STK;
	std::vector <char> Carr;
	
	while(Carr.size()<2*n)
	{ 
		if(STK.empty()||STK.top()<arr[idx])//맨 처음 or stack의 숫자가 맞춰야 하는 숫자보다 작을때
		{
			STK.push(num++); Carr.push_back('+');
		}
		
		else if(STK.top()==arr[idx])//스택의 숫자와 arr[idx]의 숫자가 같을때
		{
			STK.pop(); idx++; Carr.push_back('-');
		}
		
		else if(STK.top()>arr[idx])
		{
				std::cout<<"NO"; return;
		}
		
		else if(num>=n)
		{
			while(!STK.empty())
			{
				if(STK.top()==arr[idx])
				{
					STK.pop(); idx++; Carr.push_back('-');	
				}
				else
				{
					std::cout<<"NO";  return;	
				}	
			}
		}
	}	
	
	for(int i=0;i<2*n;i++)
	{
		std::cout<<Carr[i]<<'\n';	
	}
	return;
}