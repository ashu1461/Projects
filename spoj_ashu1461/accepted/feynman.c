#include<stdio.h>
int main()
{
	while(1)
	{
	int n;
	scanf("%d",&n);
	if(n==0)
		return 0;
	int ans=0;
	while(n>0)
	{
		ans=ans+n*n;
		n--;	

	}
	printf("%d\n",ans);
}
return 0;
}
