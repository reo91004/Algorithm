#include <iostream>


int queen(int n,bool arr1[],bool arr2[],bool arr3[],int x)
{
	static int count=0;
	if(x==n)
	{
		count++; return 0;	
	}
	for(int y=0;y<n;y++)
	{
		if(arr1[y]&&arr2[x-y+n]&&arr3[x+y])
		{
			arr1[y]=false; arr2[x-y+n]=false; arr3[x+y]=false;	
			queen(n,arr1,arr2,arr3,x+1);
			arr1[y]=true; arr2[x-y+n]=true; arr3[x+y]=true;
		}
	}
	return count;
}

int main()
{
	int n;
	std::cin>>n;
	bool *arr1,*arr2,*arr3;//arr2= 왼쪽 대각선 //arr3는 오른쪽 대각선
	arr1=new bool[n] ; arr2=new bool[2*n-1] ; arr3=new bool[2*n-1] ;
	for(int i=0;i<n;i++)
	{
		arr1[i]=true; arr2[2*i]=true; arr2[2*i+1]=true; arr3[2*i]=true; arr3[2*i+1]=true;	
	}
	std::cout<<queen(n,arr1,arr2,arr3,0)<<std::endl;	
	delete [] arr1;delete []arr2; delete []arr3;
	return 0;		
}