/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyprob'
date->Sat Jan  5 14:33:00 IST 2013*/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int compare_function(const void *a , const void *b){
	int *x =(int *)a;
	int *y=(int *)b;
	return *x-*y;
}
int A[100001];
int main()
{
	int test;
	scanf("%d",&test);
	char s[1000];
//	int A[1000];
	int no,i,j;
	while(test--){
		scanf("%d",&no);
		for(i=0;i<no;i++){
			scanf("%s %d",s,&A[i]);
		}
		sort(A,A+no);
//		qsort(A,no,sizeof(A[0]),compare_function);
		long long int total=0;
		for(i=0;i<no;i++){
			total=total+abs(A[i]-(i+1));
		}
		printf("%lld\n",total);
	}
return 0;
}

