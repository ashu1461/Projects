/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'major'
date->Sat Jun  2 04:45:00 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,flag=0;
		int A[20002];
		int no,i,p;
		scanf("%d",&n);
		if(n%2==0)
			p=n/2;
		else
			p=n/2+1;
	//	printf("here is p%d\n",p);
		for(i=0;i<20002;i++)
			A[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&no);
			A[no+1000]++;
		}
		for(i=0;i<20002;i++)
		{
			if(A[i]>n/2)
			{
				printf("YES %d\n",i-1000);
				flag=1;
				break;
			}
		}
		if(flag!=1)
			printf("NO\n");

	}

return 0;
}

