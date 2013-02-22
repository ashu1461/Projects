/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> '2ndone'
date->Sun Jun  3 15:36:08 IST 2012*/
#include<stdio.h>
int function(int n,int k)
{
	if(n==1)
	{	printf("recursion for n,k %d %d\n",n,k);
		return 1;
	}
	else
	{	printf("recursion for n,k %d %d\n",n,k);
		return ((function(n-1,k)+k-1)%n)+1;
	}
}

int main()
{
	int n,k;
	while(1)
	{
	scanf("%d %d",&n,&k);
	if(n==0)
		break;
	int i=1,ans=0;
	int prev=1;
	while(i<n)
	{
//		printf("i and prev %d %d\n",i,prev);
		prev=(prev+k-1)%(i+1)+1;
		ans=ans+prev;
		i++;
	}
//	printf("%d %d %d\n",n,k,function(n,k));
	printf("%d %d %d\n",n,k,prev);
	}
return 0;
}

