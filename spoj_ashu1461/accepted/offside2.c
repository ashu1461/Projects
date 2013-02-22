#include<stdio.h>
int main()
{
	int a=1,b,i,j;
	while(a!=0)
	{
		scanf("%d %d",&a,&b);
		int A[100000],B[100000];
		if(a==0)
			break;
		for(i=0;i<a;i++)
		{
			scanf("%d",&A[i]);
		}
		for(i=0;i<b;i++)
		{
			scanf("%d",&B[i]);
		}
		int min,temp;
		for(i=0;i<a;i++)
		{
			min=i;
			for(j=i;j<a;j++)
			{
				if(A[j]<A[min])
					min=j;

			}
			temp=A[min];
			A[min]=A[i];
			A[i]=temp;
		}
		for(i=0;i<b;i++)
		{
			min=i;
			for(j=i;j<b;j++)
			{
				if(B[j]<B[min])
					min=j;
			}
			temp=B[min];
			B[min]=B[i];
			B[i]=temp;
		}
		if(A[0]<B[1])
			printf("Y\n");
		else
			printf("N\n");
	}
return 0;
}
