#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	int n;
	scanf("%d",&n);
	int ans=0,i;
	for(i=5;i<=n;)
	{
		ans=ans+n/i;
		i=i*5;
	}
	printf("%d\n",ans);
	test--;
	}
	return 0;
}
