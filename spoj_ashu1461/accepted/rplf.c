/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'fast_schedule'
date->Sat Jun  9 06:28:12 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int h,m,n,counter=0;
	while(test--){
		printf("Scenario #%d: ",++counter);
		scanf("%d",&n);
		h=n/60;
		m=n%60;
		h=(9+h)%24;
		if(h<10){
			printf("0");
		}
		printf("%d:",h);
		if(m<10){
			printf("0");
		}
		printf("%d\n",m);
	}
return 0;
}

