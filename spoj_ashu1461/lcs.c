/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'longest_increasing_subsequence'
date->Tue Jun  5 01:26:56 IST 2012*/
// this code is through dynamic programming
#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if (a>=b)
		return a;
	return b;
}
int main()
{
	char s[1000],t[1000];
	scanf("%s %s",s,t);
	int m=strlen(s);
	int n=strlen(s);
	int lcs[m+1][n+1],i,j;
	for(i=m;i>=0;i--)
		for(j=n;j>=0;j--){
			if(i==m||j==n)
				lcs[i][j]=0;
			else
			{
				lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
				if(s[i]==t[j])
					lcs[i][j]=max(lcs[i][j],lcs[i+1][j+1]+1);
			}
		}
printf("%d\n",lcs[0][0]);
return 0;
}

