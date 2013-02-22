#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000];
	while(1)
	{
		scanf("%s %s",a,b);
		if(a[0]=='*')
			break;
	int sta=strlen(a);
	int ans=0,i,flag=0;
	for(i=0;i<sta;)
	{
		while((a[i]=='B'&&b[i]=='N')||(a[i]=='N'&&b[i]=='B'))
		{
			if(flag==0)
				ans++;
			flag=1;
			i++;
		}
		flag=0;
		while((a[i]=='B'&&b[i]=='B')||(a[i]=='N'&&b[i]=='N'))
			i++;
	}
	printf("%d\n",ans);
	}
	return 0;
}
