/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'REPEAT'
date->Fri Jun  8 02:29:05 IST 2012*/
#include<stdio.h>
int main ()
{
	// THIS IS AWSM BITCH !!!
	// TRULY
	int test;
	scanf("%d",&test);
	while(test--){
	long long int t;
	int i;
	int n;
	scanf( "%d\n", &n );
	long long int answer;
	for(i=0; i<n; ++i )
	{
		scanf( "%lld", &t );
		if( i == 0 )
			answer = t;
		else
			answer ^= t;
//		printf("here we are %d\n",answer);

	}
	printf( "%lld\n", answer );
	}
return 0;
}
