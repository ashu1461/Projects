#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n>0)
	{
		int no,i;
		scanf("%d",&no);
		long long x,s=0;
		for(i=0;i<no;i++)
		{
			scanf("%lld",&x);
			s=(s+x)%no;

		}
		if(s==0)
			printf("YES\n");
		else
			printf("NO\n");
		n--;

	}
	return 0;
}
