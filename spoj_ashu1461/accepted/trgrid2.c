#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int a,b;
	while(test>0)
	{
	scanf("%d %d",&a,&b);
	if(a==b && a%2==0)
	printf("%c\n",'L');
	else if (a==b && a%2!=0)
	printf("%c\n",'R');
	else if (a>b)
		if(b%2!=0)
			printf("%c\n",'D');
		else
			printf("%c\n",'U');
	else if(b>a)
		if(a%2!=0)
			printf("%c\n",'R');
		else
			printf("%c\n",'L');
	test--;
	}
	return 0;
}

