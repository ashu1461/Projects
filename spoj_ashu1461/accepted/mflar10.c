/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'tautogram'
date->Sat Jun  2 04:21:41 IST 2012*/
#include<stdio.h>
#include<string.h>
int main()
{
	char s[10000];
	char p;
	while(1)
	{
		scanf("%[^,\n]",s);
		scanf("%c",&p);
			if(s[0]=='*')
				break;
		int sta=strlen(s),i,flag=0,ans=0;
		char c=s[0];
		for(i=0;i<sta;i++)
		{
			if(s[i]!=' ')
			{
				c=s[i];
				break;
			}
		}
		char d;
		if(97<=c && c<=122)
			d=(char)((int)c-32);
		else
			d=(char)((int)c+32);
		// set the flag if it is a space
		for(i=1;i<sta;i++)
		{
			if(s[i]==' ')
				flag=1;
			else
				if(flag==1)
					if(s[i]!=d&&s[i]!=c)
					{
						ans=1;
						break;
					}
					else
					{
						flag=0;
					}

		}
		if(ans==1)
			printf("N\n");
		else
			printf("Y\n");
	}
return 0;
}

