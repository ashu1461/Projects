#include<stdio.h>
char function2(char index)
{
	if(index=='R')
		return 'D';
	else if(index=='D')
		return 'L';
	else if(index=='L')
		return 'U';
	else 
		return 'R';

}
char function(long long int a,long long int b,char index)
{
	if(a==1&&b!=1)
		return function2(index);
	else if(b==1&&a!=1)
		return function2(index);
	else 
		if(index=='R'||index=='L')
		return function(a-1,b,function2(index));
		else 
		return function(a,b-1,function2(index));

}
int main()
{
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	printf("%lld %lld\n",a,b);
	printf("%c\n",function(a,b,'R'));
	return 0;

}
