/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'cut_the_silver_bar'
date->Sat Jun  9 10:22:06 IST 2012*/
// Just remembered the formulae was 2^x+1 < number < 2^x
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)
			break;
		int nn = log(n)/log(2);
		printf("%d\n",nn);
	}
return 0;
}

