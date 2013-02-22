#include<stdio.h>
int main()
{
	while(1)
	{
	long long a1,a2,a3;
	scanf("%lld %lld %lld",&a1,&a2,&a3);
	if(a3!=0)
	{
	if(a3-a2==a2-a1)
		printf("AP %lld\n",a3+a3-a2);
	else
		printf("GP %lld\n",a3*a3/a2);
	}
	else
	{
		return 0;
	}
	}
	return 0;
}
