#include<stdio.h>
int main()
{
	long long  a,b;
	scanf("%lld %lld",&a,&b);
	long long i,j;
	for(i=1;i<=a+b;i++)
	{
		if(((a-2*i+4)*i)/2==a+b)
		{
			printf("%lld %lld\n",(a-2*i+4)/2,i);
			return 0;
		}
	}
	return 0;
}
