/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyproblem'
date->Thu Dec 20 22:49:28 IST 2012*/
#include<stdio.h>
#include<stdlib.h>
int compare_function1(const void *a,const void *b){
	  int *x =( int *)a;
 int *y=( int *)b;
	return *y-*x;
}
int compare_function(const void *a,const void *b){
	 int *x =( int *)a;
	 int *y=(int *)b;
	return *x-*y;
}
int main()
{
	 int n;
while(1){
	scanf("%d",&n);
	if(n==0){
		break;
	}
 int A[n];
	 int B[n];
	long long int ans = 0;
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);

	}
	for(i=0;i<n;i++){
		scanf("%d",&B[i]);
	}
	qsort(A,n,sizeof(A[0]),compare_function);
	qsort(B,n,sizeof(B[0]),compare_function1);
	for(i=0;i<n;i++){
		ans=ans+(long long int )A[i]*B[i];
	}
	printf("%lld\n",ans);

}
return 0;
}

