#include<stdio.h>
int main()
{
	int a=1,b=1;
		scanf("%d %d",&a,&b);
	while(!(a==0&&b==0))
	{
		// now we have the numbers 
		int min=10001,min1=10001,min2=10001,i,no;
		for(i=0;i<a;i++)
		{
			scanf("%d",&no);
			if(no<min)
				min=no;
		}
		for(i=0;i<b;i++)
		{
			scanf("%d",&no);
			if(no<=min1)
			{
				min2=min1;
				min1=no;
				
			}
			else if(no<=min2 && no>=min1)
			{
				min2=no;
			}
		}
		if(min2==10001)
			min2=min1;
//		printf("%d %d %d\n",min,min1,min2);
		if(min==min1==min2 || min==min2 || min > min1)
			printf("N\n");
		else
			printf("Y\n");
		scanf("%d %d",&a,&b);
	}
	return 0;
}
