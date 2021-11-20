#include <iostream>
#include <vector>



int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin>>N;
	
	int STKMAX;
	int* Arr= new int [N];
	int* NGE=new int [N];
	std::vector <int> STK;	
	
	for(int i=0;i<N;i++)
		std::cin>>Arr[i];
	//input data
	
	NGE[N-1]=-1;
	STK.push_back(Arr[N-1]);
	STKMAX=STK.back();
	
	for(int i=N-2;i>=0;i--)
	{
		if(STKMAX<=Arr[i])
			{NGE[i]=-1;	STK.push_back(Arr[i]);	STKMAX=Arr[i];}
		else//STKMAX>Arr[i]
		{
			if(Arr[i]>=Arr[i+1]&&NGE[i+1]>Arr[i])
			{
				NGE[i]=NGE[i+1];	STK.push_back(Arr[i]);
			}
			
			else
			{
				for(int j=STK.size()-1;j>=0;j--)
				{
					if(Arr[i]<STK[j])
					{
						NGE[i]=STK[j];	STK.push_back(Arr[i]);
						break;	
					}	
				}
			}
		
		}
	}
	//Set NGE[]
	
	for(int i=0;i<N;i++)
		std::cout<<NGE[i]<<' ';
	
	delete []Arr;delete []NGE;
	Arr=NGE=NULL;
	return 0;
}