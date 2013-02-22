#include<stdio.h>
int main()
{
	int test,flag=0;
	scanf("%d",&test);
	while(test>0)
	{
		flag++;
		int ans;
		int n;
		scanf("%d %d",&ans,&n);
		int A[n];
		int i,j,max,temp;
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(i=0;i<n;i++)
		{
			max=i;
			for(j=i;j<n;j++)
				if(A[j]>A[max])
					max=j;
			temp=A[i];
			A[i]=A[max];
			A[max]=temp;
		}
		int count=0;
		for(i=0;i<n;i++)
		{
		count=count+A[i];
		if(count>=ans)
		{
			printf("Scenario #%d:\n%d\n",flag,i+1);
			break;
		}
		if(i==n-1)
			printf("Scenario #%d:\nimpossible\n",flag);
		}
		test--;
	}
}
