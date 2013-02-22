/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'rootciph'
date->Fri Jun  1 17:51:05 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("%lld\n",a*a-2*b);
	}
return 0;
}

