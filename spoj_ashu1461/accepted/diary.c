#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	char c;
	scanf("%d",&test);
		scanf("%c",&c);
	while(test>0)
	{
		char c;
	char s[1002];
	scanf("%[^,\n]",s);
		scanf("%c",&c);
	int A[26],i;
	for(i=0;i<26;i++)
		A[i]=0;
	int sta=strlen(s);
	int max=-100,index;
	for(i=0;i<sta;i++)
	{
		if(s[i]!=' ')
		{
		A[(int)s[i]-65]++;
		if(A[(int)s[i]-65]>max)
		{
			index=(int)s[i]-65;
			max=A[(int)s[i]-65];
		}
		}
	}
	int flag=1;
	for(i=0;i<26;i++)
	{
		if(A[i]==max&&i!=index)
		{
			printf("NOT POSSIBLE\n");
			flag=0;
			break;
		}

	}
	if(flag!=0)
	{
	int d=index-4,p;
	if(d<0)
	{
		d=d+26;
		printf("%d ",d);
	}
	else
	printf("%d ",d);
	for(i=0;i<sta;i++)
	{
		if(s[i]!=' ')
		{
			if((int)(s[i])-d<65)
			{
				s[i]=s[i]+26-d;
				printf("%c",s[i]);
			}
			else
			{
				printf("%c",s[i]-d);
			}
		}
		else
			printf("%c",s[i]);
	}
	printf("\n");
	}
	test--;
}
return 0;
}
