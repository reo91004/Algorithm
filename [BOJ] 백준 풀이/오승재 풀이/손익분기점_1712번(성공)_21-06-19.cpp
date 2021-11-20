#include<iostream>
using namespace std;


int main()
{
	int fixedcost,variablecost,income;
	cin>>fixedcost>>variablecost>>income;
	
	if(variablecost>=income)
	{
		cout<<"-1"<<endl;
		return 0;
		}
	/*while(fixedcost>=(income-variablecost)*count)
	{
		count++;
	}시간 초과 당했음(시간제한 0.35초)*/
	cout<<fixedcost/(income-variablecost)+1<<endl;//시간제한 통과함
	return 0;
}