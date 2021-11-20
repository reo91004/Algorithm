#include <iostream>

class Arr
{
	private:
		int num;
		int length;
	public:
		Arr(int num=0,int length=0): num(num), length(length)
		{}
		int Getnum()const
		{	return num;	}
		int Getlength()const
		{	return length;	}	
};

Arr* Findmax(Arr& a1,Arr& a2,int num);

int main()
{	
	int n;
	std::cin>>n;
	
	int* arr= new int[n];
	for(int i=0;i<n;i++)	
		std::cin>>arr[i];
	Arr* arr0=new Arr[n]; //arr[i]::X
	Arr* arr1=new Arr[n]; //arr[i]::O
	arr0[0]=Arr(); arr1[0]=Arr(arr[0],1);
	
	for(int i=1;i<n;i++)
	{
		//arr0[i]
		if(arr0[i-1].Getlength()>arr1[i-1].Getlength())	arr0[i]=arr0[i-1];
	
		else if(arr0[i-1].Getlength()<arr1[i-1].Getlength()) arr0[i]=arr1[i-1];
		
		else arr0[i]=arr0[i-1].Getnum()<arr1[i-1].Getnum() ? arr0[i-1] : arr1[i-1];
		//arr1[i]
		int idx=i-1;
		while(idx>=0)
		{
			Arr* ptr=Findmax(arr0[idx],arr1[idx],arr[i]);
			if(ptr==NULL)
				idx--;
			else
			{
				arr1[i]=Arr(arr[i],ptr->Getlength()+1);
				break;	
			}
		}	
	//	std::cout<<"arr1["<<i<<"]=="<<arr1[i].Getlength()<<"arr0["<<i<<"]=="<<arr0[i].Getlength()<<std::endl;
	}
	
	if(arr0[n-1].Getlength()>arr1[n-1].Getlength())
		std::cout<<arr0[n-1].Getlength();
	else
		std::cout<<arr1[n-1].Getlength();
		
	delete []arr;
	delete []arr0;
	delete []arr1;

	return 0;
}

Arr* Findmax(Arr& a1,Arr& a2,int num)
{
	if(a1.Getnum()>=num&&a2.Getnum()>=num)	return NULL;
	
	if(a1.Getnum()<num&&a2.Getnum()>=num)	return &a1;
	
	if(a1.Getnum()>=num&&a2.Getnum()<num)	return &a2;
	
	else	return a1.Getlength()>a2.Getlength() ? &a1: &a2;
}