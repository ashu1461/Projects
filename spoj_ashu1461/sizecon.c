#include<stdio.h>
int main()
{
	int n,no,result=0;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%d",&no);
		result =no > 0 ? result + no :result;
		n--;
	}
	printf("%d\n",result);
	return 0;
}
