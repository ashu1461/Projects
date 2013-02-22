/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'copy'
date->Sun Jun  3 11:57:34 IST 2012*/
#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	int no;
	scanf("%d",&no);
	char s[no][1000];
	int i,j;
	int flag1=0,flag2=0;
	int set=-1;
	// flag1 for arabic and flag2 for english
	for(i=0;i<no;i++)
	{
		scanf("%s",s[i]);
		if(flag1!=1)
		for(j=0;j<strlen(s[i]);j++)
		{
			if(s[i][j]=='#')
			{
				flag1=1;
				break;
			}
		}
		if(flag2!=1)
		{
			for(j=0;j<strlen(s[i]);j++)
			{
				if(s[i][j]!='#')
				{
					flag2=1;
					set=i;
					break;
				}
			}
		}
	}
	int h=0;
	if((flag1==0&&flag2==1)||(flag1==1&&flag2==0))
		for(i=0;i<no;i++)
		{
			if(i==0)
				printf("%s",s[i]);
			else
			printf(" %s",s[i]);
		}
	else
	{
		for(i=set+1;i<no;i++)
		{
			if(h==0)
			{
			printf("%s",s[i]);
			h=1;
			}
			else
			{
				printf(" %s",s[i]); 
			}
		}
		if(h==0)
			{
			printf("%s",s[set]);
			h=1;
			}
			else
			{
				printf(" %s",s[set]); 
			}
		for(i=0;i<set;i++)
		{
		if(h==0)
			{
			printf("%s",s[i]);
			h=1;
			}
			else
			{
				printf(" %s",s[i]); 
			}
		}
	}
		printf("\n");
//	printf("block which contains the alphabets %d\n",set);
	}
return 0;
}

