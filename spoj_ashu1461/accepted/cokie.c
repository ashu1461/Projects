#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,a,d;
		scanf("%d %d %d",&n,&a,&d);
		int i;
		int ans=a;
		int next=a;
		for(i=1;i<n;i++)
		{	
			next=next+d;	
			ans=ans+next;
		}
		printf("%d\n",ans);
	}
	return 0;
}
