/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'egypt'
date->Fri Jun  1 18:42:43 IST 2012*/
#include<stdio.h>
int main()
{
	long long int a,b,c;
	int flag;
	while(1)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==0)
			break;
		if(a>b && a>c)
		{
			if(a*a==b*b+c*c)
				printf("right\n");
			else
				printf("wrong\n");
		}
		else if(b>a && b>c)
		{
			if(b*b == a*a+c*c)
				printf("right\n");
			else
				printf("wrong\n");
		}
		else if(c>a && c>b)
		{
			if(c*c==a*a+b*b)
				printf("right\n");
			else
				printf("wrong\n");
		}
		else
			printf("wrong\n");
	}
return 0;
}

