/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'woodaxegrass'
date->Sat Jun  2 03:43:39 IST 2012*/
#include<stdio.h>
int main()
{
	int test,r,c,n,i,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&r,&c,&n);
		char s[1000][1000];
		char prev[1000][1000];
		for(i=0;i<r;i++)
			scanf("%s",s[i]);
		while(n--)
		{
			for(i=0;i<r;i++)for(j=0;j<c;j++)prev[i][j]=s[i][j];
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
				{
					if(s[i][j]=='W')
					{
					//	printf("here1,i,j %d %d\n",i,j);
						if(prev[i-1][j]=='G'||prev[i+1][j]=='G'||prev[i][j-1]=='G'||prev[i][j+1]=='G')
							s[i][j]='G';
					}
					else	if(s[i][j]=='A')
					{
					//	printf("here2,i,j %d %d\n",i,j);
						if(prev[i-1][j]=='W'||prev[i+1][j]=='W'||prev[i][j-1]=='W'||prev[i][j+1]=='W')
							s[i][j]='W';
					}
					else		if(s[i][j]=='G')
					{
					//	printf("here3,i,j %d %d\n",i,j);
						if(prev[i-1][j]=='A'||prev[i+1][j]=='A'||prev[i][j-1]=='A'||prev[i][j+1]=='A')
							s[i][j]='A';
					}
				}
		}
		for(i=0;i<r;i++)
			printf("%s\n",s[i]);


	}
return 0;
}

