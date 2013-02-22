#include<stdio.h>
int main()
{
	int test;
scanf("%d",&test);
while(test>0)
{
	int n,i,j;
	scanf("%d",&n);
	int A[n],B[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	int min,temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
			if(A[j]<=A[min])
			{
				min=j;
			}
		temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
			if(B[j]<=B[min])
			{
				min=j;
			}
		temp=B[min];
		B[min]=B[i];
		B[i]=temp;
	}
	int ans=0;
for(i=0;i<n;i++)
{
ans=ans+A[i]*B[i];
}
	printf("%d\n",ans);
test--;
}
}
