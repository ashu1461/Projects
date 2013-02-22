#include<stdio.h>
long long int function(int a)
{
	if(a>=a/2+a/3+a/4)
		return a;
	return function(a/2)+function(a/3)+function(a/4);
}
int main()
{
	int  n;
	while(scanf("%d",&n)!=EOF)
	{
	printf("%lld\n",function(n));
	}
	return 0;
}
