#include<stdio.h>
int main()
{
	int a=1,b,i;
	long long int ans=0;
	while(1)
	{
		ans=0;
		scanf("%d %d\n",&a,&b);
		if(a==-1)
			break;
		int count=a;
		int n;
		for(i=0;i<a;i++)
		{
			scanf("%d",&n);
			ans=ans+n*(count);
			count--;
		}
		printf("%lld\n",ans*b);
	}
	return 0;
}
