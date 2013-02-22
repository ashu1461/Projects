/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'simple_cowcar'
date->Thu Dec  6 19:22:59 IST 2012*/
#include<stdio.h>
#include<stdlib.h>
int compare_function(const void *a,const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	return *x - *y;
}
int main()
{
	long  n,m,d,l,i;
	scanf("%ld %ld %ld %ld",&n,&m,&d,&l);
	// now what the fuck to do ?
	// hmm ! 
	long  A[n];
	for(i=0;i<n;i++){
		scanf("%ld",&A[i]);
	}
	qsort(A,n,sizeof(A[0]),compare_function);
	// obtained the sorted array ! 
	// m is the number of say tracks 
	long  selected=0 ;
	long  index=0;
	long  ans=0;
	for(i=0;i<n;i++){
		if(selected==m){
			selected = 0;
			index++;
		}
		if(A[i]-index*d>=l){
			selected++;
			ans++;
		}
	}
	// just print the answer ! 
	printf("%ld\n",ans);
	
return 0;
}

