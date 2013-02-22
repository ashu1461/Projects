/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'stonegame'
date->Fri Jun  1 18:15:54 IST 2012*/
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int no;
		scanf("%d",&no);
		int A[no];
		int i;
		int ans=0;
		for(i=0;i<no;i++)
		{
			scanf("%d",&A[i]);
			ans=ans+A[i]/(i+1);
		}
		if(ans%2==0)
			printf("BOB\n");
		else
			printf("ALICE\n");
	}
return 0;
}

