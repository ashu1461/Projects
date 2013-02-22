#include<stdio.h>
long long function(long long a)
{
	long long b;
	b=0;
	while(a>0)
	{
		b=b*10+a%10;
		a=a/10;
	}
	return b;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	long long reva=function(a);
	long long revb=function(b);
//	printf("%lld %lld\n",reva,revb);
	printf("%lld\n",function(reva+revb));
	test--;
	}
return 0;
}
