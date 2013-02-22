/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'triple_fat_ladies'
date->Mon Jun  4 01:11:31 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		long long int k;
		scanf("%lld",&k);
		printf("%lld\n",(k-1)*250+192);

	}
return 0;
}

