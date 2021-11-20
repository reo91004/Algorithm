#include <iostream>

class Stair
{
	private:
		long long arr[10];
	public:
		Stair()
		{
			for(int i=0;i<10;i++)
				arr[i]=1;	
		}
		long long Getsum()const
		{
			long long sum=0;
				for(int i=1;i<10;i++)
					{sum+=arr[i];sum%=1000000000;}
			return sum%1000000000000;	
		}
		void Find(Stair& s)
		{
			arr[0]=s.arr[1]%1000000000;
			for(int i=1;i<=8;i++)
			{
				arr[i]=(s.arr[i-1]+s.arr[i+1])%1000000000;	
			}
			arr[9]=s.arr[8]%1000000000;
		}		
};

long long SumofStair(int n);

int main()
{
	int n;
	std::cin>>n;
	
	std::cout<<SumofStair(n);
	
	return 0;	
}

long long SumofStair(int n)
{
	Stair* arr=new Stair[n];
	
	for(int i=1;i<n;i++)
	{
		arr[i].Find(arr[i-1]);
	}
	long long sum=arr[n-1].Getsum();
	delete []arr;
	
	return sum;
}