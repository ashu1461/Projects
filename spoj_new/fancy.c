/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easyprob'
date->Sat Dec 22 13:15:07 IST 2012*/
#include<stdio.h>
#include<math.h>
// fancy numbers;
unsigned long long int fact(unsigned long long int a){
	if(a==1)
	return 1;
	else
	return a*fact(a-1);
}
int main()
{
	int i;
		for(i=0;i<31;i++)
		printf("%d\n",(int)pow(2,i));

return 0;
}
