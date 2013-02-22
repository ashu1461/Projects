#include<stdio.h>
int p[510],w[510],m[10010];
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int e,f,i;
		scanf("%d %d",&e,&f);
		int n;
		scanf("%d",&n);
		int temp=1000000;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&p[i],&w[i]);
			if(w[i]<temp)
				temp=w[i];

		}
		int j,temp1;
		for(i=0;i<temp;i++)
			m[i]=0;
		for(i=temp;i<=f-e;i++)
		{
			temp=1000500;
			for(j=1;j<=n;j++){
				temp1=0;
				if(i>=w[j])
					if(m[i-w[j]]>0||i==w[j])
						temp1=p[j]+m[i-w[j]];
				if(temp1 < temp && temp1!=0)
					temp=temp1;
			}
			if(temp==1000500)
			{
				m[i]=0;
			}
			else 
				m[i]=temp;
		}
		if(m[f-e]==0)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",m[f-e]);
		test--;

	}
	return 0;
}
