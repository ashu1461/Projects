/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'bytelandianc4'
date->Sun Jun  3 00:22:11 IST 2012*/
#include<stdio.h>
#include<string.h>
int decode(int x,int y)
{
	// y = (x + i)mod 26
	// i = y-x+26 or 26 -x -y
	if(0<=y+26-x&&y+26-x<=25)
		return y+26-x;
	else
		return 26-x-y;
}
int main()
{
	int m;
	scanf("%d",&m);
	int K[m],i;
	for(i=0;i<m;i++)
	{
		K[i]=-1;
	}
	char a[100000],b[100000];
	scanf("%s %s",a,b);
	int sta=strlen(a);
	int flag[sta];
	for(i=0;i<sta;i++)
		flag[i]=0;
	for(i=0;i<sta;i++)
	{	
		if(a[i]!='*'&&b[i]!='*')
		{
			printf("decoding for %d %d %d\n",i,a[i]-65,b[i]-65);
			K[i%m]=decode(a[i]-65,b[i]-65);	
		}
	}
	for(i=0;i<m;i++)
		printf("%d ",K[i]);
	printf("\n");

	// then wtf to do ? 
		
return 0;
}

