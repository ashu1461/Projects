/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyproob'
date->Thu Dec 20 23:35:35 IST 2012*/
#include<stdio.h>
#include<stdlib.h>
int compare_function(const void *a,const void *b){
	 int *x =( int *)a;
	 int *y=(int *)b;
	return *x-*y;
}
long long int A[4];
int main()
{
	int counter=0;
	while(scanf("%lld %lld %lld %lld",&A[0],&A[1],&A[2],&A[3])!=EOF){
	qsort(A,4,sizeof(A[0]),compare_function);
	printf("Case %d: %lld\n",++counter,A[2]+A[3]);

	}

return 0;
}

