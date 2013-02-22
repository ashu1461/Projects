#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		char s[1000];
		scanf("%s",s);
		int sta=strlen(s),i;
		char stack[1000];
		int counter=0;
		for(i=0;i<sta;i++)
		{
			if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
			{	
				stack[counter]=s[i];
				counter++;
			}
			else if(s[i]==')')
			{
				counter--;
				while(stack[counter]!='(')
				{
					printf("%c",stack[counter]);
					counter--;
				}
			}
			else
				printf("%c",s[i]);
		}
		printf("\n");
		test--;
	}
	return 0;
}
