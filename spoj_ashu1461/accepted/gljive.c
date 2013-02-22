/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'gljive'
date->Fri Jun  1 19:13:12 IST 2012*/
#include<stdio.h>
int main()
{
	int A[10];
	int i;
	for(i=0;i<10;i++)
		scanf("%d",&A[i]);
	int prev=A[0],sum=A[0];
	int ans;
	for(i=1;i<10;i++)
	{
		prev=sum;
		sum=sum+A[i];
		if(sum>100)
		{
			if(sum-100>100-prev)
				ans=prev;
			else
				ans=sum;
			break;
		}
		else if (sum==100)
		{
			ans=sum;
			break;
		}
		
	}
		if(sum<100)
			ans=sum;
		printf("%d\n",ans);
		
return 0;
}

