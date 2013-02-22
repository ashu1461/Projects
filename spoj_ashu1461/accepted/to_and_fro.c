#include<stdio.h>
#include<string.h>
int main()
{ 	
	int n;
	while(1)
	{
	scanf("%d",&n);
	if(n==0)
		return 0;
	char s[1000];
	scanf("%s",s);
	int sta=strlen(s);
	int i=0,count=0,count1=0;
	int flag=0;
	int k=2*n-1,j=1;
	int m=sta/n;
	while(count!=n)
	{
		if(count1==m)
		{
			count++;
			count1=0;
			k=k-2;
			j=j+2;
			i=count;
			flag=0;
		}
		if(count>=n)
			break;
		printf("%c",s[i]);
		if(flag==0)
		{
			i=i+k;
			flag=1;
		}
		else if(flag==1)
		{
			i=i+j;
			flag=0;
		}
		count1++;
	}
	printf("\n");
	}
	return 0;

}
