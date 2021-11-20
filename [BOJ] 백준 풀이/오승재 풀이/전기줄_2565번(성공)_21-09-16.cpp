#include <iostream>
#include <algorithm>


class powerline
{
	private:
		int lpos;
		int rpos;
	public:
		powerline(int lpos=0,int rpos=0):lpos(lpos), rpos(rpos)
		{	}
		int Getlpos() const
		{	return lpos;	}
		int Getrpos() const
		{	return rpos;	}	
};

bool compare(powerline& p1, powerline& p2)
{
	return p1.Getlpos()<p2.Getlpos();	
}
void Printarr(powerline*,int n);

int main()
{
	int n;
	std::cin>>n;
	
	int* Lsublength, *Rsublength;
	Lsublength=new int [n]; Rsublength=new int [n];
	
	powerline* arr= new powerline [n];
	//InputData
	for(int i=0;i<n;i++)
	{
		int lpos, rpos;
		std::cin>>lpos>>rpos;
		arr[i]=powerline(lpos,rpos);
		Lsublength[i]=Rsublength[i]=1;	
	}
	//InputData	
	std::sort(arr,arr+n,compare);
	
//	Printarr(arr,n);
	
	//Search Rsublength
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i].Getrpos() > arr[j].Getrpos() && Rsublength[i] <= Rsublength[j])
			{
				Rsublength[i] = Rsublength[j] + 1;
			}
		}
	}
	//Search Rsublength	
	
	
	//Search Lsublength
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i + 1; j <=n-1 ; j++)
		{
			if (arr[i].Getrpos()< arr[j].Getrpos()&& Lsublength[i] <= Lsublength[j])
			{
				Lsublength[i] = Lsublength[j] + 1;
			}
		}
	}
	//Search Lsublength
	
	int lengthmax = 0;

	for (int i = 0; i < n; i++)
	{
		lengthmax = std::max(lengthmax, Rsublength[i] + Lsublength[i] - 1);
	//	std::cout << "sublength[" << i << "] == " << Rsublength[i] + Lsublength[i] - 1 << std::endl;
	}

	std::cout << n-lengthmax;
	
	delete []arr; delete []Lsublength; delete []Rsublength;
	Lsublength=Rsublength=NULL;
	arr=NULL;
	
	return 0;
}


void Printarr(powerline* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		std::cout<<"arr ["<<i<<"]: lpos == "<<arr[i].Getlpos()<<" rpos == "<<arr[i].Getrpos()<<std::endl;
	}	
}