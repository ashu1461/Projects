#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	long long a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	long long num=(c*2)/(a+b);
	printf("%lld\n",num);
	long long start,diff;
	diff=(b-a)/(num-5);
	start=a-2*diff;
	long long i;
	for(i=1;i<=num;i++)
	{
		printf("%lld ",start+(i-1)*diff);
	}
	printf("\n");
	test--;
	}
}
