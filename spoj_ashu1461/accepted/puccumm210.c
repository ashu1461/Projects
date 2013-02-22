/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'A_summatory'
date->Wed Jun  6 09:30:56 IST 2012*/
#include<stdio.h>
// function = (1/60)*n*(n+1)*(n+2)*(3*n^2+6*n+1)
long long int div=1000000003;
long long int function(long long int n){
	long long int ans2=0,ans=0;
	long long int ans1=0;
	ans1=(n*(n+1)*(n+2));
	ans2=(3*n*n+6*n+1);
	if(ans1%5==0)
		ans1=ans1/5;
	else
		ans2=ans2/5;
	if(ans1%3==0)
		ans1=ans1/3;
	else
		ans2=ans2/3;
	if(ans1%2==0)
		ans1=ans1/2;
	else
		ans2=ans2/2;
	if(ans1%2==0)
		ans1=ans1/2;
	else
		ans2=ans2/2;
	ans1=ans1%div;
	ans2=ans2%div;
	ans=(ans1*ans2)%div;
	return ans;
}
int main()
{
int test;
scanf("%d",&test);
long long int no;
while(test--){
	scanf("%lld",&no);
	printf("%lld\n",function(no));
}
return 0;
}

