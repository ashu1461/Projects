#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	long long a,b ;
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",b);
	test--;
	}
return 0;
}
