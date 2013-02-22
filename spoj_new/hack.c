#include<stdio.h>
// this is our brand new and sexy binary search ! 
int binary_search(long A[],long target);
long  n;
int compare_function(const void *a,const void *b) {
		int *x = (int *) a;
			int *y = (int *) b;
				return *x - *y;
}
int main(){
//	int n;
	scanf("%ld",&n);
	long  k;
	scanf("%ld",&k);
	long A[n];
	long i,ans=0;
	for(i=0;i<n;i++)
		scanf("%ld",&A[i]);
	qsort(A,n,sizeof(A[0]),compare_function);
	for(i=0;i<n;i++){
		
	if(binary_search(A,A[i]+k)==0)
	{
//		printf("found the %d\n",A[i]);
	ans++;
	}
	}
	printf("%ld\n",ans);
	return 0;
}
int binary_search(long A[],long target){
	// now we have to search target in the array A 
	long low = 0;
	long high = n-1;
	long  mid ;
	while(low<=high){
		mid = (high + low)/2;
		if(A[mid]==target)
			return 0;
		else if(A[mid]<target){
			low=mid+1;
		}
		else
			high=mid-1;
	}
	return 1;
}
