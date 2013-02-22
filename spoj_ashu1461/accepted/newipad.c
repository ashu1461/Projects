#include<stdio.h>
#include<string.h>
int n;
int function(char* s)
{
	int j;
	for(j=0;j<n;j++)
		printf("%c%c",s[j],s[j]);
	printf("\n");
	for(j=0;j<n;j++)
		printf("%c%c",s[j],s[j]);
	printf("\n");
	return 0;

}
int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int i;
		char s[100];
		for(i=0;i<n;i++)
		{

			scanf("%s",s);
			function(s);
		}
	}
	return 0;
}
