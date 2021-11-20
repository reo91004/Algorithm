#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	
	int n;
	std::cin>>n;
	int* partial_length=new int[n+1]{};
	int max_length=0;
	
	for(int i=0;i<n;i++)
	{
		int num; std::cin>>num;
		for(int l=max_length;l>=0;l--)
		{
			if(partial_length[l]<num&&(partial_length[l+1]==0||partial_length[l+1]>num))
			{
				std::cout<<"l+1, num :"<<l+1<<"	"<<num<<std::endl;
				partial_length[l+1]=num; 
				if(l==max_length)
					max_length++;	
			}	
		}	
	}
	
	std::cout<<max_length;	
	
	delete [] partial_length;
	
	return 0;
}