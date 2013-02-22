#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int flag1,flag2,flag3;
	int ans=0;
	flag1=0,flag2=0,flag3=0;
	for(i=0;i<n;i++)
	{
		char s[100];
		scanf("%s",s);
		if(s[0]=='1'&&s[2]=='4')
			flag1++;
		if(s[0]=='1'&&s[2]=='2')
			flag2++;
		if(s[0]=='3'&&s[2]=='4')
			flag3++;
	}
	ans=ans+flag1/4;
	flag1=flag1%4;
	if(flag2%2==0)
	{
	ans=ans+flag2/2;
	flag2=0;
	}
	else if(flag2%2!=0 &&flag2>1)
	{
	ans=ans+flag2/2;
		flag2=1;
	}
	if(flag2==1)
	{
		if(flag1>=2)
		{
		flag1=flag1-2;
		ans=ans+1;
		flag2=0;
		}
		else
		{
			ans=ans+1;
			flag2=0;
		}
	}
//	printf("flags and ans %d %d %d\n",flag1,flag2,ans);
	while(flag3>0 && flag1 >0)
	{
		flag3=flag3-1;
		flag1=flag1-1;
		ans=ans+1;
	}
//	printf("flag1 and 3s and ans %d %d %d\n",flag1,flag3,ans);
	// flag2 is either 0 or 1;
	// and either flag3=0 or flag1=0 // so
	// what are the cases reamaining ? flag1<2 and flag2=1 or all besides flag1 are zero ! 
	if(flag3!=0)
		ans=ans+flag3;
	else if(flag1!=0)
		ans=ans+1;
	ans=ans+flag2+1;
	printf("%d\n",ans);
	return 0;
}
