/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> ''
date->Wed May 30 20:15:59 IST 2012*/
#include<stdio.h>
int main()
{
	int e,f,s,n,e1,f1,s1,n1;
	while(1)
	{
	scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&n,&e1,&f1,&s1,&n1);
	if(e==-1)
		break;
	float e2,f2,s2,n2;
	e2=e*(1.0)/e1;
	f2=f*(1.0)/f1;
	s2=s*(1.0)/s1;
	n2=n*(1.0)/n1;
	int max;
	float max1=e2;
	if(f2>max1)
		max1=f2;
	if(s2>max1)
		max1=s2;
	if(n2>max1)
		max1=n2;
	if((int)max1-max1==0)
		max=(int)max1;
	else
		max=(int)max1+1;
//	printf("max is %d\n",max);
	printf("%d %d %d %d\n",(max*e1-(int)e),(max*f1-(int)f),(max*s1-(int)s),(max*n1-(int)n));
	}
return 0;
}
