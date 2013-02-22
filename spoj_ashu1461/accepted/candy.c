#include<stdio.h>
int main()
{
	int no;
	while(1)
	{
		int A[10000];
		scanf("%d",&no);
		if(no==-1)
			break;
		int i;
		int max=-1,total=0,n;
		for(i=0;i<no;i++)
		{
			scanf("%d",&n);
			A[i]=n;
			if(n>max)
				max=n;
			total=n+total;
		}
		int avg=total/no;
		if(total%no!=0)
			printf("-1\n");
		else
		{
			int ans=0;
			for(i=0;i<no;i++)
				if(A[i]>avg)
					ans=ans+A[i]-avg;
			printf("%d\n",ans);
		}

	}
return 0;
}
