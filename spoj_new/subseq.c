/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'dynameic programming'
date->Sat Jan  5 18:03:37 IST 2013*/
#include<stdio.h>
int n;
int function(int A[],int s,int sum){
	// two possibilites if we take a particular element and ifwe not take it :D
	printf("here for element %d and sum %d\n",s,sum);
	if(sum==47)
		return 1;
	if(s==n){
		return 0;
	}
	return function(A,s+1,sum+A[s])+function(A,s+1,sum);
}
int main()
{
	int i;
	int test;
	scanf("%d",&test);
	while(test--){
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	
	}
	int j,counter=0,sum;
	for(i=0;i<n;i++){
		sum=0;
		for(j=i;j<n;j++){
			sum=sum+A[j];
			if(sum==47){
				printf("here %d %d\n",i,j);
				counter++;
				}
		}
	}
	printf("%d\n",counter);
	}
return 0;
}

