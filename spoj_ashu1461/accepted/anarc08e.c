#include<stdio.h>
int ncr(int a,int b)
{
	return fact(a)/(fact(b)*fact(a-b));
}
int fact(int a)
{
	if(a==1||a==0)
		return 1;
	else
		return a*fact(a-1);
}
int main()
{
	int a,b;
	while(1)
	{
		scanf("%d %d",&a,&b);
		int i;
		int ans=0;
		if(a==-1)
			break;
		if(a>=b)
		{
			if(b==0)
				ans=1;
			else
				for(i=1;i<=b;i++)
				{
					ans=ans+ncr(a+1,i);
				}
		}
		else
		{
//	printf("here for %d %d\n",a,b);
			if(a==0)
				ans=1;
			else
				for(i=1;i<=a;i++)
				{
//			printf("calling ncr %d %d\n",b+1,a);
					ans=ans+ncr(b+1,i);

				}
		}
		if(a+b==ans)
		printf("%d+%d=%d\n",a,b,ans);
		else
			printf("%d+%d!=%d\n",a,b,a+b);
	}
	return 0;
}
