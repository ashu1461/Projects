/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'family_problems'
date->Sun Jun  3 20:21:38 IST 2012*/
#include<stdio.h>
int main()
{
	int n;
	char s[1000]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(scanf("%d",&n)>0)
	{
		int i=1;
		int counter=1;
		int ans=0;
		while(1)
		{
			ans=ans+counter;
			if(ans>=n)
				break;
			counter++;

		}
		printf("TERM %d IS %c\n",n,s[counter-1]);
	}
return 0;
}

