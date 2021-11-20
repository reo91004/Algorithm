#include <iostream>

class Step
{
	private:
		int key;
		int count;
	public:
	Step(int key=0, int count=0):key(key), count(count)
	{}
	int Getkey()const
	{	return key;	}
	int Getcount()const
	{	return count;	}
	void countpp()
	{	count++;	}
	void resetcount()
	{	count=0;	}
	friend Step operator+(Step& s1,Step& s2);
};
	
Step operator+(Step& s1,Step& s2)
	{	return Step(s1.Getkey()+s2.Getkey(),s1.Getcount()+s2.Getcount());	}

int Maxscore(Step* arr,int n);

int main()
{
	int n;
	std::cin>>n;
	
	Step* arr=new Step[n];
	for(int i=0;i<n;i++)
		{int k; std::cin>>k; arr[i]=Step(k);}
		
	std::cout<<Maxscore(arr,n);
	
	delete []arr;
	return 0;
}

int Maxscore(Step* arr,int n)
{
	Step* arr0=new Step[n];//count==0으로 유지
	Step* arr1=new Step[n];//count==1으로 유지
	
	arr0[0]=arr[0]; arr1[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		if(i==1)
		{
			arr0[i]=arr[i]; arr0[i].resetcount();
			arr1[i]=arr[i]+arr0[i-1]; arr1[i].countpp();	
		}
		else
		{
			if(arr0[i-2].Getkey()>arr1[i-2].Getkey())
				{arr0[i]=arr[i]+arr0[i-2]; arr0[i].resetcount();}
			else
				{arr0[i]=arr[i]+arr1[i-2]; arr0[i].resetcount();}
			arr1[i]=arr[i]+arr0[i-1]; arr1[i].countpp();	
		}	
	}
	
	return arr0[n-1].Getkey()>arr1[n-1].Getkey()? arr0[n-1].Getkey():arr1[n-1].Getkey();
}