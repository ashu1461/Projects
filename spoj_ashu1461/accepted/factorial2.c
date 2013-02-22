#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	int n;
	scanf("%d",&n);
	int a[200];
	a[0]=1;
	int index=0;
	int temp,i;
	while(n>1)
	{
		temp=0;
		for(i=0;i<=index;i++)
		{
			temp=(a[i]*n)+temp;
			a[i]=temp%10;
			temp=temp/10;
		}
		while(temp>0)
		{
			index=index+1;
			a[index]=temp%10;
			temp=temp/10;
		}
		n--;
	}
	for(i=index;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	test--;
	}
	return 0;
}
