#include <iostream>
#include <cmath>

int FindRemainder(int A,int B, int C);

int main()
{
	int A,B,C;
	std::cin>>A>>B>>C;
	
	std::cout<<FindRemainder(A,B,C);
	
	return 0;
}

int FindRemainder(int A,int B, int C)
{
	long long remainder=1;
	int root=sqrt(B);
	int sq=sqrt(root);
	if(root>sqrt(root)*2+root+(root-sq*sq))//둘로 나누는게 더 이득일때
	{	remainder=FindRemainder(A,root,C);	}
	else//여기서 깡 계산이 더 이득임
	{
		for(int i=0;i<root;i++)
		{	remainder=remainder*(A%C)%C;	}
	}
	
	int temp=remainder;
		
	for(int i=1;i<root;i++)
	{	remainder=remainder*temp%C;	}
	
	for(int i=root*root;i<B;i++)
	{	remainder=remainder*(A%C)%C;	}	

		return remainder;
}