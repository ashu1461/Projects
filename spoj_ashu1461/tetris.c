#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
	if(a==0)
		return b;
	else if(b==0)
		return a;
	if(a>b)
		return (a%b,b);
	else
		return (a,b%a);
	return 0;
}
long long int lcm(long long int a, long long int b)
{
	long long int n;
	for(n=1;;n++)
	{
		if(n%a == 0 && n%b==0)
			return n;
	}
}
int main()
{
	long long int a,b;

	while(1)
	{
		scanf("%lld %lld",&a,&b);
		if(a==0)
			break;
		if(a>b)
		{
			if(a%b==0)
			{
				printf("%lld",a/b);
			}
			else
				printf("%lld",(a*b)/gcd(a,b));
		}
		else if(b>a)
		{
			if(b%a==0)
				printf("%lld",b/a);
			else
				printf("%lld",(a*b)/gcd(a,b));
		}
		else
			printf("1");
		printf("\n");
	}
	return 0;
}
