#include<stdio.h>
#include<string.h>
int NumOfWords(const char str[],const int len)
{
 int i=0;
 int words=0;
 while(str[i]==' ')
 {i++;}
 for(i;i<len;i++)
 {
     if(str[i]==NULL)
         words++;
     else if(str[i]==' '&&(str[i+1]!=' '&&str[i+1]!=NULL))
         words++;
 }
    return words;
    
}
int main()
{
 char str[1000000];
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);
    str[len-1]=NULL;
    int words=NumOfWords(str,len);
    
    printf("%d",words);
    return 0;
}