#include<stdio.h>
int main(){
	long n;
	long test;
	scanf("%ld",&test);
	while(test--){
	scanf("%ld",&n);
	long A[n];
	long i;
	for(i=0;i<n;i++)
		scanf("%ld",&A[i]);
	// now ? 
	long Max[n];
	// initalize it to zero ! 
	long number[n];
	long j;
	for(i=0;i<n;i++){
		Max[i]=1;
		for(j=0;j<i;j++)
		{
			if(Max[i]<=Max[j]&&A[i]==(A[j]+1))
				Max[i]=Max[j]+1;

		}
//prlongf("------------------\n");
//		for(j=0;j<n;j++)
//			prlongf("%d ",Max[j]);
//		prlongf("-----------------\n");
	}
	long max=0;
	for(i=0;i<n;i++)
		if(Max[i]>max)
			max=Max[i];
	printf("%ld\n",n-max);
//	prlongf("\n");
	}
return 0;
}
