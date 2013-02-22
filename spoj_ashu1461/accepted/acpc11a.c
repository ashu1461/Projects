/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'arabicandenglish'
date->Sun Jun  3 09:57:09 IST 2012*/
#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	int no;
	char c;
	while(test--)
	{
		char s[1000];
		scanf("%d",&no);
		scanf("%c",&c);
		scanf("%[^,\n]",s);
		printf("%s\n",s);
		int i,sta=strlen(s);
		int flag1=0,flag2=0;
		// flag 1 for # and flag 2 for abbb
		for(i=0;i<sta;i++)
		{
			if(flag1!=1&&s[i]=='#')
			{
				flag1=1;
			}
			if(flag2!=1&&s[i]!='#'&&s[i]!=' ')
			{
				flag2=1;
			}
		}
		printf("%d %d\n",flag1,flag2);
		if((flag1==1&&flag2==0)||(flag1==0&&flag2==1))
		{
			printf("%s\n",s);
		}
		else
		{
			int start,end,flag3=0;
			for(i=0;i<sta;i++)
			{
				if(s[i]!='#'&&s[i]!=' '&&flag3!=1)
				{
					start=i;
					flag3=1;
				}
				if(s[i]!='#'&&s[i]!=' ')
				{
					end=i;
				}
			}
			if(start
			printf("start and end %d %d\n",start,end);
			for(i=end+1;i<sta;i++)
				printf("%c",s[i]);
			for(i=start;i<=end;i++)
				printf("%c",s[i]);
			for(i=0;i<start;i++)
				printf("%c",s[i]);
			printf("\n");
		}
	}
return 0;
}

