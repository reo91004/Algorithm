#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int len=str.length();
    int i=0,num=0;
    while(1)
    {
        if(str[i]!=' ')
            break;
        i++;
    }
    while(i<len-1)
    {
        if(str[i]==' '&&str[i+1]!=' ')
            {num++;last=i;}
         i++;
    }
 
    cout<<num+1<<endl;
}