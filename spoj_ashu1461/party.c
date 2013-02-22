#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&b,&a);
	// b is the budget and a is the number of parties 
	int A[b][a];
	int i,j;
	int cost[a],fun[a];
	for(i=0;i<a;i++)
		scanf("%d %d",&cost[i],&fun[i]);
	for(i=0;i<b;i++)
		for(j=0;j<a;j++)
			A[i][j]=0;
	printf("here\n"); 
	for(i=0;i<b;i++)
		for(j=0;j<a;j++)
			if(i<cost[j])
				A[i][j]=A[i][j-1];
			else
			{
				if(A[i][j-1]>A[i-cost[j]][j-1]+fun[j])
					A[i][j]=A[i][j-1];
				else
					A[i][j]=A[i-cost[j]][j-1]+fun[j];
			}
	
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
		printf("%d ",A[i][j]);
		}
	printf("\n");
	}
}
