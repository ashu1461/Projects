#include<stdio.h>
#include<math.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
double a ,b,c,d,e,f,vol;
	scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
vol=sqrt(4*a*a*b*b*c*c- a*a*(b*b+c*c - d*d)*(b*b+c*c-d*d) - b*b*(c*c+a*a - e*e)*(c*c+a*a-e*e) - c*c*(a*a + b*b - f*f)*(a*a+b*b-f*f) + (b*b +c*c - d*d)*(c*c+a*a- e*e)*(a*a+b*b - f*f))/12;
printf("%.4lf\n",vol);
}
return 0;
}
