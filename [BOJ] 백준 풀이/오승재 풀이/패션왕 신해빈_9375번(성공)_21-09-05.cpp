#include <iostream>

class Dress
{
	private:
		std::string Type;
		int TypeCount;
	public:
		Dress() {}
		Dress(std::string Type, int N=0): Type(Type),TypeCount(N)
		{}
		std::string GetType() const
		{	return Type;	}
		void PlusCount()
		{	TypeCount++;	}
		int GetTypeCount() const
		{	return TypeCount;	}
		void PrintInfo()
		{
			std::cout<<"Type is : "<<Type<<'\n'<<"TypeCount is : "<<TypeCount<<'\n';	
		}
};

Dress* TypeChecker(Dress arr[],int len, std::string Type);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int Test_N;
	std::cin>>Test_N;
	
	for(int i=0;i<Test_N;i++)
	{
		Dress arr[30];
		int clothes, TypeCount=0; 
		std::cin>>clothes; 
		
		//옷의 정보를 저장함
		for(int j=0;j<clothes;j++)
		{
			std::string Name, Type;
			std::cin>>Name>>Type; 
			Dress* Ptr=TypeChecker(arr,TypeCount,Type);
			//새로운 Type의 옷이 있으면 새롭게 등록함
			if(TypeCount==0||Ptr==NULL)
			{
				arr[TypeCount++]=Dress(Type,1);
			}
			//기존에 있던 Type의 옷임
			else
			{
				Ptr->PlusCount();	
			}
		}
		//옷의 정보를 저장함
				
		int Count_Combination=1;
		for(int i=0;i<TypeCount;i++)
		{
			Count_Combination*=arr[i].GetTypeCount()+1;	
		}
		std::cout<<Count_Combination-1<<'\n';
			
	}	
	
}

Dress* TypeChecker(Dress arr[],int len, std::string Type)
{
		for(int i=0;i<len;i++)
		{
			if(arr[i].GetType()==Type)
			{
				return &arr[i];
			}	
		}
		return NULL;
}