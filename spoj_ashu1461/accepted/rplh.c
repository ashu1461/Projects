/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'Hard_Launching'
date->Sat Jun  9 10:47:08 IST 2012*/
#include<stdio.h>
#include<math.h>
// range=u*u*sin2(0)/g
// OMG ! < We should multiply by 0.5 instead of dividing by 2 in case of double numbers  >
int main()
{
	int test;
	scanf("%d",&test);
	int a,b,counter=0;
	double sin2;
	while(test--){
		printf("Scenario #%d: ",++counter);
		scanf("%d %d",&a,&b);
		sin2 = (9.806*a)/b/b;
		// now we have the value of sin2()
		if(sin2>1 || sin2 < -1){
			printf("-1\n");
		}
		else{
			sin2=0.5*asin(sin2);
			sin2=sin2*180/(2*acos(0.0));
			printf("%.2lf\n",sin2);
		}	
	}
return 0;
}
