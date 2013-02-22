/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'invisiblepoint'
date->Sun Jun  3 12:33:00 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int no;
		scanf("%d",&no);
		if(no%2==0)
			no=(no-2)/2;
		else
			no=(no-2)/2+1;
		printf("%d\n",no+2);
	}
return 0;
}

