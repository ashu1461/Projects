#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		while(n>0)
		{
			ans=ans+n/5;
			n=n/5;
			
		}
		printf("%d\n",ans);
		test--;
	}
	return 0;
}
