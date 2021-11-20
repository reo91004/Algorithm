#include <iostream>
#include <string>
#define len length
#define Npos std::string::npos

int LCS(std::string s1,std::string s2);
//s1.len()>=s2.len()

int main()
{
    std::string s1,s2;
  
    std::cin>>s1>>s2;
    //Input Data

    std::cout<<LCS(s1,s2);

    return 0;    
}

int LCS(std::string s1,std::string s2)
{
    if(s1.len()<s2.len())
    {
        return LCS(s2,s1);
    }
    
    int * Arr= new int[s2.len()+1];
    
    for(int i;i<s2.len()+1;i++)
    {
    	Arr[i]=0;	
    }
    int Max=0;
    
    for(int i=0;i<s2.len()+1;i++)
    {
    	for(int j=Max;j>=0;j--)
    	{
    		int idx=s1.find(s2[i],Arr[j]);
    		if(idx!=Npos)
    		{
    			if(j==Max)
    				{Max++;}
    			if(Arr[j+1]==0||Arr[j+1]>idx+1)
    				{Arr[j+1]=idx+1;}
    		}	
    	}	
    	//std::cout<<"Max is "<<Max<<std::endl;
    }
 	delete [] Arr;
    return Max;   
}