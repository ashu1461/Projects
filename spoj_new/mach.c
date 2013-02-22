#include<stdio.h>
int func(int a,int b,int c)
{
	if(b==0)
	{
		if(c%a)return 1;
		else return 0;
	}
	int x=1;
	while(1)
	{
		if(c>a){
		if(((c-a)*x)%b==0)
			return 1;}
		else
			return 0;
		x++;
	}
}
int main()
{
	int a,b,c,d,n;
	scanf("%d",&n);
	while(n--)
	{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	(func(a,b,c) && func(a,b,d))?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
