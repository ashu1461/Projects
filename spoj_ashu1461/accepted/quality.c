/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'quality'
date->Fri Jun  1 18:30:40 IST 2012*/
#include<stdio.h>
int main()
{
	int a,b,c,a1,b1,c1;
	int counter=1;
	int time=0,total=0;
	while(scanf("%d %d %d %d %d %d",&a,&b,&c,&a1,&b1,&c1)!=EOF)
	{
		time=0;
		total=0;
		if(a!=0)
		{
			total++;
			time=time+a+20*60*(a1-1);	
		}
		if(b!=0)
		{
			total++;
			time=time+b+20*60*(b1-1);
		
		}
		if(c!=0)
		{
			total++;
			time=time+c+20*60*(c1-1);
			
		}
		printf("team %d: %d, %d\n",counter,total,time);
		counter++;
	}
return 0;
}

