#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int num;
	cin>>num;
	int len=log10(num)+1;
	int *arr=new int[len];
	int i=0;
	while(num)
	{
		arr[i++]=num%10;
		num/=10;	
	}	
	sort(arr,arr+len);
	for(int i=len-1;i>=0;i--)
	{
		num+=arr[i];
		if(i==0)
			break;
		num*=10;	
	}
	cout<<num<<endl;
	return 0;
}