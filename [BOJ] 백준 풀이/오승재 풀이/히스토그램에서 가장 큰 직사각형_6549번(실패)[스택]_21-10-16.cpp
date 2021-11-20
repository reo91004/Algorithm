#include <iostream>
#include <stack>


std::stack <long long*> Make_STM(long long arr[],long long n);//STM=SmallThanMe나보다 작은애!

int main()
{
	
	while(1)
	{
		long long n;//직사각형의 수
		std::cin>>n;
		
		if(n==0)
			{	return 0;	}
		
		long long* arr=new long long [n];
		
		for(long long i=0;i<n;i++)
			std::cin>>arr[i];
		//Input Data
		
		std::stack <long long*> STM=Make_STM(arr,n);
		long long maximum=0;
		
		for(long long i=0;i<n;i++)
		{
			long long len;
			if(*STM.top()==-1)
			{
				len=n-i;
			}
			else
			{	
				len=(STM.top()-(arr+i));
			}
		//	std::cout<<"len ["<<i<<"] is :"<<len<<"\n";
			if(maximum<len*arr[i])
			{
				maximum=len*arr[i];	
			}
		//	std::cout<<"["<<i<<"] = "<<len*arr[i]<<'\n';
			STM.pop();
		}
		while(STM.size()>1)
			STM.pop();
		delete STM.top();
		std::cout<<maximum<<'\n';
		
		delete []arr;				
	}	
	
}

std::stack <long long*> Make_STM(long long arr[],long long n)
{
	std::stack <long long*> temp;
	std::stack <long long*> STM;
	
	long long* Minus=new long long;	*Minus=-1;
	STM.push(Minus);
	
	for(long long i=n-1;i>=0;i--)
	{
		while(!temp.empty()&&*temp.top()>=arr[i])
			{	temp.pop();	}
		if(temp.empty())
			{	temp.push(arr+i);	STM.push(Minus);	}
		else
			{	STM.push(temp.top());	temp.push(arr+i);	}	
	}	
	while(!temp.empty())
		temp.pop();
	//Set STM
	return STM;
}
//STM=SmallThanMe나보다 작은애! STM은 나보다 오른쪽에있는 처음 만나는 나보다 작은수
