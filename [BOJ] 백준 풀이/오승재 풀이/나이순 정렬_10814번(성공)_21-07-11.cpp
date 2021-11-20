#include <iostream>
#include <algorithm>
using namespace std;

class member{

	private:
		int age;
		int order;
		string name;
	public:
		member()
		{}
		member(int age,int order,string name):age(age),order(order), name(name)
		{}
		friend bool compare(member&,member&);
		friend ostream& operator<<(ostream& os,member& m);
};

bool compare(member& m1,member& m2);
ostream& operator<<(ostream& os,member& m);
int main()
{
	int memnum; cin>>memnum;
	
	member*arr=new member[memnum];
	for(int i=0;i<memnum;i++)
	{
		int age;string name; cin>>age>>name;
		arr[i]=member(age,i,name);
	}
	sort(arr,arr+memnum,compare);
	
	for(int i=0;i<memnum;i++)
	{
		cout<<arr[i]<<'\n';	
	}	
}

bool compare(member& m1,member& m2)
{
	if(m1.age==m2.age)
	{
		return m1.order<m2.order;
	}
	return m1.age<m2.age;
}

ostream& operator<<(ostream& os,member& m)
{
	os<<m.age<<' '<<m.name;
	return os;	
}