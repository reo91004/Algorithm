#include <iostream>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin>>N;
	
	int SUBMAX;
	int* Arr= new int [N];
	int** NGE=new int* [N];
		
	for(int i=0;i<N;i++)
		std::cin>>Arr[i];
	//input data
	NGE[N-1]= new int (-1);
	SUBMAX=Arr[N-1];
	
	for(int i=N-2;i>=0;i--)
	{
		if(Arr[i]>=SUBMAX)
		{
			NGE[i]=NGE[N-1]; SUBMAX=Arr[i];	
		}
		
		else if(Arr[i]<Arr[i+1])//Case 1
		{
			NGE[i]=&Arr[i+1];	
		}
		else if(Arr[i]>=Arr[i+1]&&*NGE[i+1]>Arr[i])//Case 2
		{
			NGE[i]=NGE[i+1];	
		}
		
		else //Arr[i]>=Arr[i+1]&&*NGE[i+1]<=Arr[i]
		{
			int* ptr=NGE[i+1];
			while(*ptr<=Arr[i])
			{	
				ptr++;	
			}
			NGE[i]=ptr;
		}
	
	}
	//Set NGE[]
	
	for(int i=0;i<N;i++)
		std::cout<<*NGE[i]<<' ';
	
	delete NGE[N-1];
	delete []Arr;delete []NGE;
	Arr=NULL; NGE=NULL;
	return 0;
}