/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'alaska'
  date->Fri Jun  1 18:51:30 IST 2012*/
#include<stdio.h>
int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int A[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		int temp,min=i,j;
		for(i=0;i<n;i++)
		{
			min=i;
			for(j=i;j<n;j++)
				if(A[j]<=A[min])
					min=j;
			temp=A[i];
			A[i]=A[min];
			A[min]=temp;
		}
		// now done with the sorting
		int prev=0;
		int flag=0;
		for(i=1;i<n;i++)
		{
			if(A[i]-A[i-1]>200)
			{
				flag=1;
			break;
			}
		}
		if(2*(1422-A[n-1])>200)
			flag=1;
		if(flag==1)
			printf("IMPOSSIBLE\n");
		else
			printf("POSSIBLE\n");
	}
return 0;
}

