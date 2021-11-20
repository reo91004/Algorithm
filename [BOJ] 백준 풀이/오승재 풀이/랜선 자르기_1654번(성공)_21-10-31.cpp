#include <iostream>
#include <algorithm>

int binary_length(int wires[],int k,int n);
int number_of_cuttedwires(int wires[],int k,int length);

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	
	int k,n;
	std::cin>>k>>n;
	//k==가지고있는 랜선수 n==필요한 랜선수
	int* wires=new int [k];
	
	for(int i=0;i<k;i++)
	{	std::cin>>wires[i];	}
	//wires[0]=802;wires[1]=743;wires[2]=457;wires[3]=539;
	//Input Data
	std::sort(wires,wires+k);
	
	std::cout<<binary_length(wires,k,n);
	
	delete [] wires;
	
	return 0;
}

int binary_length(int wires[],int k,int n)
{
	unsigned int start=1;
	int end=wires[k-1];
	int mid;
	while(end>start)
	{
		mid=(start+end)/2;
		if(number_of_cuttedwires(wires,k,mid)<n)//mid>answer
		{
			end=mid-1;	
		}
		else//number_of_cuttedwirds()>=n //mid<=answer
		{
			start=mid+1;
		}
		//std::cout<<mid<<std::endl;	
	}
	if(number_of_cuttedwires(wires,k,start)<n)//start>answer
	{
		while(number_of_cuttedwires(wires,k,start)<n)
		{start--;}	
	}
	else//start<=answer
	{
		while(number_of_cuttedwires(wires,k,start+1)>=n)
		{start++;}
	}
	return start;
}

int number_of_cuttedwires(int wires[],int k,int length)
{
	int sum=0;
	for(int i=0;i<k;i++)
		{sum+=wires[i]/length;}
	
	//std::cout<<"sum is :"<<sum<<std::endl;
	return sum;
}