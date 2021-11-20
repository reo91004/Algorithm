#include <iostream>
#include <stack>
#include <deque>


std::deque <int*> Make_RSTM(int arr[],int n);//STM=SmallThanMe나보다 작은애!
std::deque <int*> Make_LSTM(int arr[],int n);//STM=SmallThanMe나보다 작은애!


int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	while(1)
	{
		int n;//직사각형의 수
		std::cin>>n;
		
		if(n==0)
			{	break;	}
		
		int* arr=new int [n];
		
		for(int i=0;i<n;i++)
			std::cin>>arr[i];
		//Input Data
		
		std::deque <int*> RSTM=Make_RSTM(arr,n);
		std::deque <int*> LSTM=Make_LSTM(arr,n);
		long long maximum=0;
		
		for(int i=0;i<n;i++)
		{
			long long Rlen,Llen;
			if(*RSTM.back()==-1)
			{	Rlen=n-i;	}
			else
			{	Rlen=(RSTM.back()-(arr+i));	}
			if(*LSTM.back()==-1)
			{	Llen=i+1; 	}
			else
			{	Llen=((arr+i)-LSTM.back()); 	}
		//	std::cout<<" Rlen = "<<Rlen; std::cout<<" Llen = "<<Llen; std::cout<<"	"<<i<<std::endl;
			long long submax=arr[i]*(Rlen+Llen-1);
			if(maximum<submax)
			{
				maximum=submax;
				//std::cout<<maximum<<"\n";	
			}
			RSTM.pop_back(); LSTM.pop_back();
		}
		while(RSTM.size()>1)
			RSTM.pop_back();
		while(LSTM.size()>1)
			LSTM.pop_back();
		delete RSTM.back(); delete LSTM.back();
		std::cout<<maximum<<'\n';
		
		delete []arr;				
	}	
	
	return 0;
	
}

std::deque <int*> Make_RSTM(int arr[],int n)
{
	std::stack <int*> temp;
	std::deque <int*> STM;
	
	int* Minus=new int (-1);
	STM.push_back(Minus);
	
	for(int i=n-1;i>=0;i--)
	{
		while(!temp.empty()&&*temp.top()>=arr[i])
			{	temp.pop();	}
		if(temp.empty())
			{	temp.push(arr+i);	STM.push_back(Minus);	}
		else
			{	STM.push_back(temp.top());	temp.push(arr+i);	}	
	}	
	while(!temp.empty())
		temp.pop();
	//Set STM
	return STM;
}
//STM=SmallThanMe나보다 작은애! STM은 나보다 오른쪽에있는 처음 만나는 나보다 작은수

std::deque <int*> Make_LSTM(int arr[],int n)//STM=SmallThanMe나보다 작은애!
{
	std::stack <int*> temp;
	std::deque <int*> STM;
	
	int* Minus=new int (-1);
		
	for(int i=0;i<n;i++)
	{
		while(!temp.empty()&&*temp.top()>=arr[i])
			{	temp.pop();	}
		if(temp.empty())
			{	temp.push(arr+i);	STM.push_front(Minus);	}
		else
			{	STM.push_front(temp.top());	temp.push(arr+i);	}	
	}	
	while(!temp.empty())
		temp.pop();
		
	STM.push_front(Minus);
	//Set STM
	return STM;	
}