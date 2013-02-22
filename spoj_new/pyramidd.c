 #include<math.h>
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{

		double u,v,w,U,V,W;
		scanf("%lf %lf %lf %lf %lf %lf",&u,&v,&w,&W,&V,&U);
		//scanf("%f %f %f %f %f %f",&u,&U,&v,&V,&w,&W);
		double vol;
		vol=sqrt(4*u*u*v*v*w*w- u*u*(v*v+w*w - U*U)*(v*v+w*w-U*U) - v*v*(w*w+u*u - V*V)*(w*w+u*u-V*V) - w*w*(u*u + v*v - W*W)*(u*u+v*v-W*W) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12;
		printf("%.4lf\n",vol);
	}
	return 0;
}
