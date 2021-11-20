#include <iostream>
using namespace std;

int main()
{
	int n;
	cin.tie(NULL);//cin을 cout으로 부터 untie합니다.
	ios::sync_with_stdio(false);//c 표준 stream과 c++표준 stream의 동기화를 끊습니다.
	//참고 C언어 팁_ios::sync_with_stdio(false),cin.tie(NULL) 사용버과 설명[부제] cin, cout, endl함수의 속도향상법
	cin>>n;
	int arr[10001]={0,};
	for (int i = 0; i < n; i++)
	{
		cin >> n;
		arr[n]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while(arr[i])
		{
			cout<<i<<'\n';arr[i]--;
		}
	}
	return 0;
}