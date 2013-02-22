/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'mademethink'
date->Thu Dec 20 16:10:23 IST 2012*/
#include<stdio.h>
#include<math.h>
long long int function (long long int a){
	if(a==1)
		return 1;
	else return a*function(a-1);
}
int main()
{
	long long int n;
	scanf("%lld",&n);
	printf("%lld\n",function(n)+(long long int)pow(2,n)-n);
return 0;
}

