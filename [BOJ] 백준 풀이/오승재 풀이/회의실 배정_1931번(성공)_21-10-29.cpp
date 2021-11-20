#include <iostream>
#include <utility>
#include <algorithm>
#define fs first
#define sd second
#define Pair std::pair<int,int>

bool compare(Pair p1,Pair p2);
void print_meetings(Pair meetings[],int n);


int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(NULL);
    int n;
    std::cin>>n;

    Pair* meetings=new Pair[n]{};
	
    for(int i=0;i<n;i++)
    {
        int start,end;
        std::cin>>start>>end;
        
        meetings[i]=std::make_pair(start,end);
    }
    //Input Data
    
    std::sort(meetings,meetings+n,compare);
	//Sorting Data by meeting time /Ascending order
    int count=0, time=0;
    for(int i=0;i<n;i++)
    {
        if(meetings[i].fs>=time)
        {
            time=meetings[i].sd; count++;
        }
    }
    
    print_meetings(meetings,n);

    std::cout<<count;

    delete [] meetings;

    return 0;
}

bool compare(Pair p1,Pair p2)
{
    if(p1.sd==p2.sd)
    {
        return p1.fs<p2.fs;
    }
    else
    {
        return p1.sd<p2.sd;
    }
}

void print_meetings(Pair meetings[],int n)
{
	for(int i=0;i<n;i++)
	{
		std::cout<<"meetings ["<<i<<"] is : <"<<meetings[i].fs<<", "<<meetings[i].sd<<">\n";
	}
	return;
}