/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'divide_and_conquer'
date->Fri Jan  4 18:02:39 IST 2013*/
#include<stdio.h>
long long int A[100002];
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--){
		long long int no,i;
		scanf("%lld",&no);
		for(i=0;i<no;i++){
			scanf("%lld",&A[i]);
		}
		long long int begin=0,last=no-1;
		long long int max=0,max1=0;
		while(begin<last){
			//		printf("%lld %lld\n",begin,last)	;
			if(A[begin]>A[last]){
				max1=A[last]*(last-begin);
				last--;
			}
			else{

				max1=A[begin]*(last-begin);
				begin++;
			}
			if(max1>max)
				max=max1;
			//:			printf("max is %lld\n",max1);
		}
		printf("%lld\n",max);
	}

	return 0;
}

