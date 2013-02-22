/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'Maxiumum-Quadilateral-Area'
date->Thu Dec  6 18:20:16 IST 2012*/
#include<math.h>
#include<stdio.h>
int main()
{
	int test;
	// we know that maximum area for a quadilateral is given by 
//	sqrt(s-a)...)
	double a,b,c,d;
	scanf("%d",&test);
	while(test--){
		double ans;
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		double s = (a+b+c+d)/2;
		 ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n",ans);
	}
return 0;
}

