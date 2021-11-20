//stack을 이용해서 풀음 백준 17298번 
#include <iostream>
#include <stack>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin>>N;
	
	int* arr= new int [N];
	std::stack <int> temp;
	std::stack <int> NGE;	
	
	for(int i=0;i<N;i++)
		std::cin>>arr[i];
	//Input Data	
		
	for(int i=N-1;i>=0;i--)
	{
		while(!temp.empty()&&temp.top()<=arr[i])
			{	temp.pop();	}
		if(temp.empty())
			{	temp.push(arr[i]); NGE.push(-1);	}
		else//temp.empty()==false
			{	NGE.push(temp.top()); temp.push(arr[i]);	}			
	}
	
	//Set NGE
	
	while(!NGE.empty())
	{
		std::cout<<NGE.top()<<' ';
		NGE.pop(); 	
	}
	
	//Show NGE
	delete []arr;
	arr=NULL;
	
	return 0;
}