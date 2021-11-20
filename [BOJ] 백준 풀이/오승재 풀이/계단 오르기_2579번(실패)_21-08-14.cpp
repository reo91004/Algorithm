#include <iostream>

class Step
{
	private:
		int value;
		int count;
	public:
		Step(int value=0,int count=0):value(value), count(count)
		{}
		int Getvalue()const
		{	return value;	}
		int Getcount()const
		{	return count;	}
		void countplus()
		{count++;}
		void resetcount()
		{count=0;}
		friend Step operator+(Step& s1,Step& s2);
};

Step operator+(Step& s1,Step& s2)
{
	return Step(s1.Getvalue()+s2.Getvalue(),s1.Getcount()+s2.Getcount());
}

void FindMax1(Step* STR1,Step* STR2, int n);
void FindMax2(Step* STR1,Step* STR2, int n);


int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n;
	std::cin>>n;
	
	Step* STR1=new Step[n];
	Step* STR2=new Step[n];
	
	for(int i=0;i<n;i++)
	{
		int key; std::cin>>key;
		STR1[i]=Step(key);	
	}
	
	FindMax1(STR1,STR2,n);
	for(int i=0;i<n-1;i++)
	{
		STR2[i]=Step();	
	}
	
	FindMax2(STR1,STR2,n);
	
	std::cout<<STR2[n-1].Getvalue();
	
	delete []STR1;
	delete []STR2;
	
	return 0;
}

void FindMax1(Step* STR1,Step* STR2, int n)
{
	
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			STR2[i]=STR1[i];	
		}
		else if(i==1)
		{
			STR2[i]=STR1[i]+STR2[i-1];
			STR2[i].countplus();	
		}
		else
		{
			if(STR2[i-1].Getvalue()>STR2[i-2].Getvalue()&&STR2[i-1].Getcount()<1)//이전 계단 
			{
				STR2[i]=STR1[i]+STR2[i-1];
				STR2[i].countplus();
					
			}	
			else
			{
				STR2[i]=STR1[i]+STR2[i-2];	
				STR2[i].resetcount();
			}
		}
	}
		
}

void FindMax2(Step* STR1,Step* STR2, int n)
{
	int temp=STR2[n-1].Getvalue();
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			STR2[i]=STR1[i];	
		}
		else if(i==1)
		{
			STR2[i]=STR1[i];	
		}
		else
		{
			if(STR2[i-1].Getvalue()>STR2[i-2].Getvalue()&&STR2[i-1].Getcount()<1)//이전 계단 
			{
				STR2[i]=STR1[i]+STR2[i-1];
				STR2[i].countplus();
					
			}	
			else
			{
				STR2[i]=STR1[i]+STR2[i-2];	
				STR2[i].resetcount();
			}
		}
	}
	if(temp>STR2[n-1].Getvalue())
	{
		STR2[n-1]=Step(temp);	
	}
}
