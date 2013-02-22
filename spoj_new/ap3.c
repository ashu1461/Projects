/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'caluclation_disastero'
date->Mon Dec 10 18:03:01 IST 2012*/
#include<stdio.h>
#include<math.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
	long long int  p,q,r;
	scanf("%lld %lld %lld",&p,&q,&r);
	long long int  b = (5*q+7*p+2*r);
	long long int x = ((p+q));
	//long long int d = (q-p)/(n-6);
//	long long int a = p - 2*d ; 
	 long double c = (long double)b/x;
	 long double d = (long double)r/x;
	long  double disc =sqrt((c*c)-48*d);
	printf("double is %Lf and b is %lld \n ",disc,b);
	long  long int   n = (c+disc)/2;

	printf("%lld\n",n);

	int i;
//	for(i=1;i<=n;i++){
	//..	printf("%lld ",a+(i-1)*d);
//	}
	printf("\n");
	}
return 0;
}

