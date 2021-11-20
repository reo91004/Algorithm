#include <iostream>
#include <utility>
#include <vector>
#define Pair std::pair<int,int>
#define fs first
#define sd second
// Pair.fs=Weight, Pair.sd=Value 

int Find_Maximum_Value (Pair items [],int N,int K);
void print_items(int Values[],int n);

int main()
{
     int N,K;
    std::cin>>N>>K;
    
    //N== number of items, K== affordable Weight
    Pair* items=new Pair[N];

    for(int i=0;i<N;i++)
    {
        int W,V;
        std::cin>>W>>V;
       
        items[i]=std::make_pair(W,V);
    }
    //Input Data

    std::cout<<Find_Maximum_Value(items,N,K);

    delete [] items;

    return 0;
}

int Find_Maximum_Value (Pair items [],int N,int K)
{
    int* Values=new int [K+1]{};
    //index means weight
   
    for(int i=0;i<N;i++)
    {
        int w=items[i].fs, v=items[i].sd;
        //w=weight, v=value
        if(v==0)
        	continue;
        for(int j=K-w;j>=1;j--)
        {  
            if(Values[j]!=0)
            {
                Values[j+w]=std::max(Values[j+w],Values[j]+v);
            }
        }
        Values[w]=std::max(Values[w],v);
        //print_items(Values,K+1);
    }
 
    int Maximum_Value=0;

    for(int i=0;i<=K;i++)
    {
        Maximum_Value=std::max(Maximum_Value,Values[i]);
    }

    delete [] Values;
    
    return Maximum_Value;
}

void print_items(int Values[],int n)
{
	for(int i=0;i<n;i++)
		std::cout<<"Values ["<<i<<"] is :"<<Values[i]<<std::endl;
	std::cout<<std::endl;	
}