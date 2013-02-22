/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'hangover'
date->Sun Jun  3 20:02:13 IST 2012*/
#include<stdio.h>
int main()
{
	float d;
	while(1)
	{
	scanf("%f",&d);
	if(d==0.00)
		break;
	float ans=0.0;
	float n=2.0;
	while(1)
	{
	//	printf("%.2f\n",1/n*(1.0));
		ans=ans+1/n;
		if(ans>=d)
		{
			break;
		}
		n++;
	}
	printf("%d card(s)\n",(int)n-1);
	}

return 0;
}

