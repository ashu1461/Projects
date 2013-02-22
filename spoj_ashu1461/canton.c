#include<stdio.h>
int main()
{
	int n,no,flag=0;
	scanf("%d",&no);
	while(no>0)
	{
		flag=0;
		scanf("%d",&n);
		int i=1;
		int counter=1;
		while(i<n)
		{
			counter++;
			if(flag==0)
				flag=1;
			else flag=0;
			i=i+counter;

		}
//		printf("%d\n",flag);
		int m=n-i+counter;
		int x,y;
		// if flag is 1 we mean that counting has started from end 1!	
//		printf("counter and m %d %d\n",counter,m);
		if(flag==0)
		{
			x=counter;
			y=1;
			while(m>1)
			{
				x--;
				y++;
				m--;

			}
		}
		else if(flag==1)
		{
			x=1;
			y=counter;
			while(m>1)
			{
				x++;
				y--;
				m--;
			}
		}
		printf("TERM %d IS %d/%d\n",n,x,y);
		no--;
	}
	return 0;
}
