#include<string.h>
#include<stdio.h>
int A[10005];
int ascii(int j,int sta,char *s)
{
int i,index,min=1000;
int count=0;
for(i=0;i<sta;i++)
	{
		A[i]=A[i]+(int)s[(i+j)%sta];
		if(A[i]<min)
		{
			min=A[i];
			index=i;
		}
	}
for(i=0;i<sta;i++)
{
	if(min==A[i])
		count++;
}
if(j==sta-1)
	return index+1;
if(count!=1)
	return -1;
else return index+1;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	char s[1000];
	scanf("%s",s);
	int i;
	int sta=strlen(s);
	int count=0;
	for(i=0;i<sta;i++)
	{
	A[i]=0;
	}
	for(i=0;i<sta;i++)
	{
	if(ascii(i,sta,s)!=-1)
	{
		printf("%d\n",ascii(i,sta,s));
		break;
	}
	}
	test--;
	}
	return 0;
}	
