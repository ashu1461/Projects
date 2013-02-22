#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int no,counter=0;
	while(test>0)
	{
		counter++;
		scanf("%d",&no);
	int A[8];
	int i;
	for(i=0;i<8;i++)
		A[i]=0;
	char s[1000];
	scanf("%s",s);
	// 0 1 2  ... 39
	// H H H .... H
	// TTT TTH THT THH HTT HTH HHT HHH
	for(i=0;i<38;i++)
	{
		if(s[i]=='T'&&s[i+1]=='T'&&s[i+2]=='T')
			A[0]++;
		if(s[i]=='T'&&s[i+1]=='T'&&s[i+2]=='H')
			A[1]++;
		if(s[i]=='T'&&s[i+1]=='H'&&s[i+2]=='T')
			A[2]++;
		if(s[i]=='T'&&s[i+1]=='H'&&s[i+2]=='H')
			A[3]++;
		if(s[i]=='H'&&s[i+1]=='T'&&s[i+2]=='T')
			A[4]++;
		if(s[i]=='H'&&s[i+1]=='T'&&s[i+2]=='H')
			A[5]++;
		if(s[i]=='H'&&s[i+1]=='H'&&s[i+2]=='T')
			A[6]++;
		if(s[i]=='H'&&s[i+1]=='H'&&s[i+2]=='H')
			A[7]++;
	}
	printf("%d",counter);
	for(i=0;i<8;i++)
		printf(" %d",A[i]);
	printf("\n");
	test--;
	}
}
