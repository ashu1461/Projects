#include<stdio.h>
int main()
{
	long long no;
	scanf("%lld",&no);
	while(no>1)
	{
		if(no%2!=0)
		{
			printf("NIE\n");
			return 0;
		}
		no=no/2;
	}
	printf("TAK\n");
	return 0;
}
