#include<stdio.h>


int ConvertCtoN(int c)
{
	switch(c)
	{
		case 'A': case 'B': case 'C':
		return 2;
		case 'D': case 'E': case 'F':
		return 3;
		case 'G': case 'H': case 'I':
		return 4;
		case 'J': case 'K': case 'L':
		return 5;
		case 'M': case 'N': case 'O':
		return 6;
		case 'P': case 'Q': case 'R': case 'S':
		 return 7;
		 case 'T': case 'U': case 'V':
		 return 8;
		 case 'W': case 'X': case 'Y': case 'Z':
		 return 9;
		 
		 default:
		 return -1;
		}
	}
	
	int ConvertNtoT(int num)
	{
		return 2+(num-1);
		}
		
		
		int main()
		{
			int c;
			int sum=0;
			c=getchar();
			while(c!='\n')
			{
				int time=ConvertCtoN(c);
				time=ConvertNtoT(time);
				sum+=time;
				c=getchar();
				}
			printf("%d",sum);
			return 0;
			}