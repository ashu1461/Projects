#include<stdio.h>
// this is our brand new and sexy binary search ! 
int binary_search(int A[],int target);
int n;
int main(){
//	int n;
	scanf("%d",&n);
	int A[100];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	int target;
	scanf("%d",&target);
	printf("0-> target found \n");
	printf("%d\n",binary_search(A,target));
	return 0;
}
int binary_search(int A[],int target){
	// now we have to search target in the array A 
	int low = 0;
	int high = n-1;
	int mid ;
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
