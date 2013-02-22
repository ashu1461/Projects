/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyfloattoint'
date->Fri Dec 21 09:21:38 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
	double x;
	scanf("%lf",&x);
	int y = (int)x;
	double z = x - (double)y;
	printf("value of z is %lf\n",z);
	int counter=0;
	while(z!=(double)0){
		z=z*10-(double)(int)z*10;
		counter++;
	}
	printf("%d\n",counter);
	}
	
return 0;
}

