#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	int n,m;
	scanf("%d %d",&n,&m);
		if(n*m>0)
			printf("1\n");
		else
			printf("2\n");
	test--;
	}
	return 0;
}
