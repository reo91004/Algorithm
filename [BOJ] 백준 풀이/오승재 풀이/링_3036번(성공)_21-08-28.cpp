#include <iostream>
#include <numeric>

 void Show_RPM(int arr[],int len);

int main()
{
	int Number_Of_Ring;
	std::cin>>Number_Of_Ring;
	
	int* Rings= new int[Number_Of_Ring];
	
	for(int i=0;i<Number_Of_Ring;i++)
	{
		std::cin>>Rings[i];
	}
	
	Show_RPM(Rings,Number_Of_Ring);
	
	delete []Rings;
	Rings=NULL;
	
	return 0;
}


void Show_RPM(int arr[],int len)
{
	int Numerator=1, Denominator=1;
	int GCD;
	for(int i=1;i<len;i++)
	{
		Numerator*=arr[i-1]; Denominator*=arr[i];
		GCD=std::gcd(Numerator,Denominator);
		Numerator/=GCD; Denominator/=GCD;
		std::cout<<Numerator<<'/'<<Denominator<<'\n';		
	}
	
	return;
}