#include <iostream>
#include <algorithm>
#include <utility>
#define fs first
#define sd second
#define Pair std::pair <int*,int*>
enum mode{Normal,Left,Right};


Pair binary_search(int* fs,int* sd,int key, mode m); //card.fs==array start, card.sd==array end
int number_of_card(int*fs,int*sd,int*key);//card.fs==array start, card.sd==array end


int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
	int n,m;
		
	std::cin>>n;	
	int* cards=new int [n];
	for(int i=0;i<n;i++)
	{
		std::cin>>cards[i];	
	}
	//Input Data
	std::sort(cards,cards+n);
	//Sort Data
	
	std::cin>>m;
	
	for(int i=0;i<m;i++)
	{
		int key; std::cin>>key;
		Pair card=binary_search(cards,cards+n-1,key,Normal);
		std::cout<<number_of_card(cards,cards+n-1,card.fs)<<' ';
	}
	
	delete [] cards;
	
	return 0;
}

Pair binary_search(int*fs,int*sd,int key, mode m)
{
	/*
	static int count=0;
	count++;
	std::cout<<"count is :"<<count<<std::endl;
	*/
	int start=0;
	int end=sd-fs;
	int mid;
	switch(m)
	{
		case Normal:
			sd=NULL; break;
		case Left:
			sd=fs; break;
		case Right:
			sd=sd; break;
	}
	
	while(end>=start)
	{
		mid=(start+end)/2;
		if(fs[mid]==key)
			{	return Pair(fs+mid,sd);	}
		else if(fs[mid]<key)
		{	start=mid+1;	}
		else//card.fs[mid]>key
		{	end=mid-1;	}
		sd=fs+mid;	
	}
	return Pair(NULL,NULL);	
}

int number_of_card(int* fs,int*sd,int*key)
{
	if(key==NULL)
	{	return 0;	}
	
	Pair left(key,fs);
	Pair right(key,sd);
	Pair temp;
	
	while(left.fs!=NULL)
	{	temp=left; left=binary_search(left.sd,left.fs-1,*key, Left);	}
	
	left=temp;

	while(right.fs!=NULL)
	{	temp=right; right=binary_search(right.fs+1,right.sd,*key,Right);	}
	right=temp;
		
	return right.fs-left.fs+1;	
}