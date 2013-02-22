/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'permutation_combination'
date->Sun Dec 23 14:44:38 IST 2012*/
#include<stdio.h>
//Ways to distribut n identical coins among r beggars ! 
//C(n+r-1,r-1);
//so here it would be C(n+2,2)
// ---> if to allot between two ->function2 c(n+1)
long long int ans;
long long int function2(long long int N){
	if(N<=0)
		return 0;
	else return (N+1);
}
long long int function(long long int N){
	if(N<0)
		return 0;
	else
	printf("here --> %lld\n",(N+2)*(N+1)/2);
//	return ((N+2)*(N+1)/2)%1000000007;
	if(N%2==0)
	return (N*N/2)%1000000007+(3*N/2)%1000000007+1;
	else{
//	printf("here %lld\n",((N*N-1)/2)%1000000007+((3*N-1)/2)%1000000007+2);
	return ((N*N-1)/2)%1000000007+((3*N-1)/2)%1000000007+2;
//	return (N*N/2)%1000000007+(3*N/2)%1000000007+1;
	}
		
//	return (N*N/2)%1000000007+(3*N/2)%1000000007+1;
//	return 1;
}
int main()
{
	int test;
	scanf("%d",&test);
	long long int N,max_a,max_b,max_c,min_a,min_b,min_c;
	while(test--){
		ans=0;
		scanf("%lld",&N);
		scanf("%lld %lld",&min_a,&max_a);
		scanf("%lld %lld",&min_b,&max_b);
		scanf("%lld %lld",&min_c,&max_c);
		N=N-min_a-min_b-min_c;
		max_a=max_a-min_a;
		max_b=max_b-min_b;
		max_c=max_c-min_c;
		printf("allot %lld with a %lld  b %lld c  %lld\n ",N,max_a,max_b,max_c);
//		if(max_a!=0&&max_b!=0&&max_c!=0)
		ans = (function(N)-function(N-max_a-1)-function(N-max_b-1)-function(N-max_c-1)-function(N-max_a-max_b-2)-function(N-max_a-max_c-2)-function(N-max_b-max_c-2)-function(N-max_a-max_b-max_c-3))%1000000007;
//		else if(max_a!=0&&max_b!=0&&max_c==0){
//		ans =  function2(N) - function2(N -max_a -1) - function2(N-max_b -1) - function2(N- max_a -max_b -2);
//		if(max_a!=0&&max_b!=0&&max_c!=0)
		printf("%lld\n",ans);
//		else
//		printf("answer %lld\n",ans);
//		}
	}    
return 0;
}

