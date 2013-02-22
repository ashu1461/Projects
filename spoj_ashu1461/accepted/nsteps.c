#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==y || x==y+2)
		{
			if(x%2==0)
			printf("%d\n",x+y);
			else 
			printf("%d\n",x+y-1);
		}
		else
		{
			printf("No Number\n");
		}
		test--;
	}
	return 0;
}
