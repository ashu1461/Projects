/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> ''
date->Wed May 30 20:07:12 IST 2012*/
#include<stdio.h>
int main()
{
	long long int n,i;
	long long int A[19000];
	for(i=0;i<18259;i++)
	{
		A[i]=1+3*i*(i-1);
	}
	while(1)
	{
		int flag=0;
		scanf("%lld",&n);
		if(n==-1)
			break;
		for(i=0;i<18259;i++)
		{
			if(A[i]==n)
			{
				printf("Y\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		printf("N\n");
	}

return 0;
}

