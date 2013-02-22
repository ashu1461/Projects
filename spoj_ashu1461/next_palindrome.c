#include<stdio.h>
#include<math.h>
// the code is if the given no is already a palindrome 
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int A[100];
		int n;
		scanf("%d",&n);
		int counter=0;
		int p=n;
		int flag=1;
		while(n>0)
		{
			if(n%10!=9)
			{
				flag=0;
			}
			counter++;
			n=n/10;
		}
		// if the number is something on the 9 side flag will remain 1
		int a=1,k=counter/2;
		while(k!=0)
		{	
			a=a*10;
			k--;
		}
		p=p/a;
		if(flag==1)
		{
		 	printf("%d",p/10+1);
		}
		else
		{
		printf("%d",p+1);
		}
		p=p+1;
		if(counter%2!=0||counter/2==0)
		{
			p=p/10;
		}
		while(p>0)
		{
			printf("%d",p%10);
			p=p/10;
		}
		printf("\n");
		test--;
	}
	return 0;
}
