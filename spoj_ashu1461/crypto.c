#include<stdio.h>
#include<string.h>
int n;
int function(int a,int b)
{
	// a is the one which we have to encrpyt !!
	// i is the value of i !
	// n is the max possible length of cypher !! 
	if(b>a)
		return b-a;
	else 
		return b-a+26;
	return 0;

}
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
	scanf("%d",&n);
	char N[n];
	char e[100002];
	scanf("%s",e);
	char d[100002];
	scanf("%s",d);
	int len=strlen(e);
	int flag[len];
	int k,i,p;
	for(i=0;i<len;i++)
		flag[i]=0;
	for(i=1;i<len;i++)
	{
		if(e[i]!='*'&&d[i]!='*'&&flag[i]==0)
		{
			k=function((int)e[i]-65,(int)d[i]-65);
		//	printf("%d %d\n",k,i);
			p=i-n+1;
			while(p>0)
			{
				if(e[p]=='*'&&d[p]!='*'){
					e[p]=(char)(function(k,(int)d[p]-65)+65);
		//			printf("here %c %c %d thru %d\n",e[p],d[p],p,i);
					flag[p]=1;
				}
				if(n==1)
					p=p-1;
				p=p-n+1;

			}
			p=i+n-1;
			while(p<len)
			{
				if(e[p]=='*'&&d[p]!='*')
				{
					e[p]=(char)(function(k,(int)d[p]-65)+65);
		//			printf("here %c %c %d thru %d\n",e[p],d[p],p,i);
					flag[p]=1;
				}
				if(n==1)
					p=p+1;
				p=p+n-1;
			}
			flag[i]=1;
		}
	}
	printf("%s\n",e);
	test--;
	}
	return 0;
}
