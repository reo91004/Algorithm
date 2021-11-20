#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define WORDLEN 51
class word
{
	private:
		char str[WORDLEN];
		int len;
	public:
		word() {}
		word(char* str,int len): len(len)
		{
			strcpy(this->str,str);
		}
	char* Getstr(){return str;}
	friend bool compare(word w1,word w2);
	friend ostream& operator<<(ostream& os,word w);		
};

bool compare(word w1,word w2);
ostream& operator<<(ostream& os,word w);

int main()
{
	int len;
	cin>>len;
	word* arr=new word[len];
	for(int i=0;i<len;i++)
	{
		char str[WORDLEN]; cin>>str;
		arr[i]=word(str,strlen(str));	
	}
	
	sort(arr,arr+len,compare);
	
	for(int i=0;i<len;i++)
	{
		if(i!=0)
		{
			if(strcmp(arr[i-1].Getstr(),arr[i].Getstr())==0)
				continue;
		}//같으면 넘어감
		cout<<arr[i]<<'\n';		
	}
	
	delete []arr;
	return 0;
}

bool compare(word w1,word w2)
{
	if(w1.len==w2.len)
	{
		for(int i=0;i<w1.len;i++)
		{
			if(w1.str[i]!=w2.str[i])
				return w1.str[i]<w2.str[i];
		}
	}
		return w1.len<w2.len;
}

ostream& operator<<(ostream& os,word w)
{
	os<<w.str;
	return os;	
}
