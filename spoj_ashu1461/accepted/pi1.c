#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int flag1,flag2,flag3;
	int ans=0;
	flag1=0,flag2=0,flag3=0;
	char s[100];
	for(i=0;i<n;i++)
	{

		scanf("%s",s);
		if(s[0]=='1'&&s[2]=='4')
			flag1++;
		else if(s[0]=='1'&&s[2]=='2')
			flag2++;
		else if(s[0]=='3'&&s[2]=='4')
			flag3++;
	}
	ans=1+flag2/2+flag3;
	flag2=flag2%2;
	if(flag3<flag1)
	{
		flag1=flag1-flag3;
	}
	else
		flag1=0;
	ans=ans+flag1/4;
	flag1=flag1%4;
	if(flag2==1)
	{
		if(flag1>2)
		{
			ans=ans+2;
		}
		else
			ans=ans+1;
	}
	else
	{	if(flag1>0)
			ans=ans+1;
	}
	printf("%d\n",ans);
	return 0;
}
