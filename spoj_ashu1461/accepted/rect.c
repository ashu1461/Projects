#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,root;
	int flag;
	int ans=1;
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		flag=1;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
				flag++;
		}
		ans=ans+flag;
	}
	printf("%d\n",ans);
	return 0;

}
