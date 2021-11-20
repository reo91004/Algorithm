#include <iostream>
#include <utility>
#define Pair std::pair<int,int>
#define fs first
#define sd second
// Pair.fs=Weight, Pair.sd=Value 

int Find_Maximum_Value (Pair items [],int N,int K);


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
    int* Values= new int [K+1];
    for(int i=0;i<=K;i++)
    {
        Values[i]=0;
    }

    for(int i=0;i<N;i++)
    {
        if(items[i].sd==0)
        	continue;
        if(items[i].fs<=K&&Values[items[i].fs]<items[i].sd)//해당 item이 무게대비 가장 가치가 높을 때 
        {
        	Values[items[i].fs]=items[i].sd;
            for(int j=K-items[i].fs;j>=1;j--)
            {
                if(Values[j]!=0&&j!=items[i].fs)
                {
                    Values[j+items[i].fs]=std::max(Values[j+items[i].fs],Values[j]+items[i].sd);
                }
            }	
        }
        
        else
        {
            for(int j=K-items[i].fs;j>=1;j--)
            {
                if(Values[j]!=0)
                {
                    Values[j+items[i].fs]=std::max(Values[j+items[i].fs],Values[j]+items[i].sd);
                }
            }
        }
    }

    int Maximum_Value=0;

    for(int i=0;i<=K;i++)
    {
        Maximum_Value=std::max(Maximum_Value,Values[i]);
        std::cout<<"Values ["<<i<<"] is :"<<Values[i]<<std::endl;
    }

    delete [] Values;
    
    return Maximum_Value;
}