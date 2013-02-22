/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'maximumlines'
date->Sat Jun  2 04:39:41 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int counter=0;
	while(test--)
	{
		counter++;
		long long int a;
		scanf("%lld",&a);
		printf("Case %d: %lld.25\n",counter,a*a*4);
	}

return 0;
}

