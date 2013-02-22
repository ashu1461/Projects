/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyprob'
date->Fri Dec 21 00:12:06 IST 2012*/
#include<stdio.h>
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--){
		long long int a ,b;
		scanf("%lld %lld",&a,&b);
		if(b==0)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
return 0;
}

