#include <iostream>
#include <string>

using namespace std;

void swap(string& str) {
	char temp;

	temp = str[0];
	str[0] = str[2];
	str[2] = temp;
}

void solution(string s1, string s2) {
	swap(s1);
	swap(s2);

	int a = stoi(s1);
	int b = stoi(s2);

	if (a > b)
		cout << a;
	else
		cout << b;
}

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	solution(s1, s2);
}