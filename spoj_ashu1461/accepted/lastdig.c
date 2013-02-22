/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'lastdigit'
  date->Sat Jun  2 05:02:25 IST 2012*/
#include<stdio.h>
int function(int a,long long int b)
{
	if(b==0)
		return 1;
	int p=a%10;
	if (p==0)
		return 0;
	if(p==5)
		return 5;
	switch(b%4)
	{
		case 0:

			if(p%2!=0)
				return 1;
			else
				return 6;

		case 1:

			return p;

		case 2:
			return p*p%10;

		default:

			return p*p*p%10;

	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int a;
		long long int b;
		scanf("%d %lld",&a,&b);
		printf("%d\n",function(a,b));

	}
	return 0;
}

