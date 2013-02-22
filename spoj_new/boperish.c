/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'citations'
date->Thu Dec  6 23:35:38 IST 2012*/
#include<stdio.h>
int compare_function(const void *a,const void *b) {
		int *x = (int *) a;
			int *y = (int *) b;
				return *x - *y;
}
int main()
{
	int n;
	while(1){
	scanf("%d",&n);
		if(n==0)
			return 0;
	int A[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	qsort(A,n,sizeof(A[0]),compare_function);
	for(i=n;i>=1;i--)
		if(A[n-i]>=i)
			break;	
	printf("%d\n",i);
	}
return 0;
}

