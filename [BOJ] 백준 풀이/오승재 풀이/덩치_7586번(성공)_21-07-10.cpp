#include <iostream>
using namespace std;

class person
{
	private:
		int weight;
		int height;
		int rank;
	public:
		person()
		{}
		person(int weight,int height)
		: weight(weight), height(height),rank(1)
		{}
		void compare(person& p)
		{
			if(weight<p.weight&&height<p.height)
			{rank++;}
		}
		int Getrank()
		{return rank;}
};

int main()
{
	int n;
	cin>>n;
	person* arr=new person[n];
	for(int i=0;i<n;i++)
	{
		int weight,height;
		cin>>weight>>height;
		arr[i]=person(weight,height);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i].compare(arr[j]);
		}
	}
	for(int i=0;i<n;i++)
	{cout<<arr[i].Getrank()<<' ';}
	delete []arr;
	return 0;
}