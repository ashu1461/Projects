#include<string.h>
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int count=1;
	while(test>0)
	{
		int no;
		char s[100];
		scanf("%d %s",&no,s);
		int i=strlen(s),j;
		printf("%d ",count);
		for(j=0;j<i;j++)
			if(j!=no-1)
				printf("%c",s[j]);
		printf("\n");
		count++;
	test--;
	}
	return 0;
}

