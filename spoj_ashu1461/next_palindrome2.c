#include<stdio.h>
int check(int);
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;;i++)
		if(check(n+i)==1)
		{
			printf("%d\n",n+i);
			break;
		}
	test--;
	}
	return 0;
}
int check(int a)
{
	int A[1000];
	int counter=0;
	while(a>0)
	{	
		A[counter]=a%10;
		counter++;
		a=a/10;
	}
	int i;
	for(i=0;i<counter/2;i++)
	{	
		if(A[i]!=A[counter-1-i])
			return 0;

	}
		return 1;
}
