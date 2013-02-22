#include<stdio.h>
int main()
{
	int n,k,s,i,j;
	scanf("%d %d %d",&n,&k,&s);
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	int max,temp;
	for(i=0;i<n;i++)
	{
		max=i;
		for(j=i;j<n;j++)
			if(A[j]>=A[max])
				max=j;
		temp=A[i];
		A[i]=A[max];
		A[max]=temp;
	}
//	for(i=0;i<n;i++)
//		printf("%d ",A[i]);
	int ans=0;
	int count=0;
	for(i=0;i<n;i++)
	{
		count=count+A[i];
		ans++;
		if(count>=k*s)
			break;
	}
	printf("%d\n",ans);
return 0;
}
