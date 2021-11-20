#include <iostream>
#include <cstring>

#define STRLEN 1000001

int main()
{
	char s[STRLEN];
	std::cin.getline(s,STRLEN);
	int len=strlen(s);
	int count=1;
	int i=0;	
	int idx=0;
	while(s[i]==' ')
		i++;
	while(i<len)
	{
		if(s[i]==' '&&s[i+1]!=' '&&s[i+1]!=0)
			count++;
		i++;
		idx=1;
	}
	if(idx==0)
		count=0;
	std::cout<<count<<std::endl;
	return 0;
}