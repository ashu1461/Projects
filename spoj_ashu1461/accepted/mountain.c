#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,i,b,j;
		scanf("%d",&a);
		long long int A[a];
		for(i=0;i<a;i++)
		{
			scanf("%lld",&A[i]);
		}
		scanf("%d",&b);
		long long int B[b],min=1000000;
		for(i=0;i<b;i++)
		{
			scanf("%lld",&B[i]);
			for(j=0;j<a;j++)
				if(abs(A[j]-B[i])<min)
					min=abs(A[j]-B[i]);
		}
		printf("%lld\n",min);

	}
	return 0;
}
