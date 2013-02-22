#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	while(scanf("%s",s)!=EOF)
	{
	int sta=strlen(s);
	int A[sta],i;
	int flag=0,flag1=0;
	for(i=0;i<sta;i++)
	{
		if(s[i]=='_')
		{
			if(i==0||i==sta-1)
				flag1=1;
			else 
			{
				if(s[i-1]=='_')
					flag1=1;
			}
			// check whether the adjacent elements are related or not ! 

			flag=1;
		}
		else if(65<=s[i]&&s[i]<=90)
		{
			if(i==0)
				flag=1;
//			else 
//			{
//				if(65<=s[i-1]&&s[i-1]<=90)
//					flag=1;
//			}
			flag1=1;
		}
	}
	if(flag1==1&&flag==1)
	{
		printf("Error!\n");
	}
	else
	{
	for(i=0;i<sta;i++)
	{
		if(65<=s[i]&&s[i]<=90)
		{
//			printf("here %c\n",s[i],s[i]);
			printf("_%c",s[i]+32);
	//		i++;
		}
		else if(s[i]=='_')
		{
			printf("%c",s[i+1]-32,s[i+1]-32);
			i++;
		}
		else
		{
			printf("%c",s[i]);
		}

	}
	printf("\n");
	}
	}
	return 0;
}
