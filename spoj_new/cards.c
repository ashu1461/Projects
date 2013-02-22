/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'simple'
date->Thu Dec 20 15:55:08 IST 2012*/
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long int a ;
		scanf("%lld",&a);
		printf("%lld\n",((a*(a+1)*3)/2-a)%1000007);
	}
return 0;
}

