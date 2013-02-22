#include<stdio.h>
int main()
{
	int test,i;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
	int no;
	scanf("%d",&no);
	int a,b,c;
	scanf("%d %d %d",&c,&a,&b);
	int count=1;
	int ans=0;
	while(a>0 || b>0)
	{
//		printf("%d %d\n",a%c,b%c);
		ans=ans+((a%c+b%c)%c)*count;
		count=count*c;
		a=a/c;
		b=b/c;
	}
	printf("%d %d\n",no,ans);
	}
	return 0;
}
