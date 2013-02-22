#include<stdio.h>
#include<string.h>
int main()
{
	int test,i;
	scanf("%d",&test);
	while(test>0)
	{
		char s[100];
		scanf("%s",s);
		int sta=strlen(s),flag=0;
		for(i=0;i<sta;i++)
		{
			if(s[i]=='D')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		printf("Possible\n");
		if(flag==1)
		printf("You shall not pass!\n");
		test--;
	}
return 0;
}
