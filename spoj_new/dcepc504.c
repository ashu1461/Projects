/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyprob'
date->Thu Jan  3 19:17:33 IST 2013*/
#include<stdio.h>
#include<math.h>
long long int function(long long int n ,long long int k){
//	printf("here for %lld %lld\n",n,k);
	if(n==1)
		return 1;
	if(k>pow(2,n-2))
	{
		return !function(n-1,k-pow(2,n-2));
	}
	else
	{
		return function(n-1,k);
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
long long	int n,k;
	scanf("%lld %lld",&n,&k);
	if(function(n,k)==1)
		printf("Male\n");
	else
		printf("Female\n");
	}	
return 0;
}
