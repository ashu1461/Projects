/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'trianguklar_prism'
date->Fri Dec  7 23:37:47 IST 2012*/
#include<stdio.h>
#include<math.h>
// i saw the forumulae from the net  !!:D
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		double d = (double)2/3;
		double ans;
		ans = 3*pow(4*n,d)*sqrt(3)/2;
		printf("%.10lf\n",ans);
	}
return 0;
}

