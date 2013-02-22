/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'simple_geometry'
date->Fri Dec  7 14:44:28 IST 2012*/
#include<stdio.h>
#include<math.h>
// the trick involved is that the maximum area with a given length is covered by a semi circle ! :D 
int main()
{
	int N;
	double ans ;
	while(1){
		scanf("%d",&N);
		if(N==0)
			break;
		// now what to do ? 
		printf("%.2lf\n",(N*N)/(2*M_PI));
	}
		
return 0;
}

