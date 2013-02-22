/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'E_23_Stairs_pattern'
date->Thu Jun  7 05:58:18 IST 2012*/
#include<stdio.h>
int main()
{
/*	int x=2,y=1;
	int number=0;
	int flag=0;
	int i;
	for(i=0;i<100;i++){
		printf("numbers from %d to %d\n",number+1,number+23);
		if(flag==0){
			printf("from cordinates (%d,%d) to (%d,%d)\n",x,y,x,y+22);
			y=y+23;
			flag=1;
		}
		else if(flag==1){
			printf("from cordinates (%d,%d) to (%d,%d)\n",x,y,x+22,y);
			x=x+23;
			flag=0;
		}
		number=number+23;
	}*/
	char c;
	long long int no,no1,no2,xx,yy;
	while(1){
	scanf("%lld%c",&no,&c);
	if(c=='\n'){
	xx=no%46;
	yy=no/46;
	if(1<=xx&&xx<=23)
	{
		printf("%lld, %lld\n",2+23*yy ,1+23*yy+xx-1);
	}
	else if(xx==0||(24<=xx&&xx<=45))
	{
		if(xx==0){
			printf("%lld, %lld\n",24+23*(yy-1) ,24+23*(yy-1));
		}
		else{
			xx=xx-23;
			printf("%lld, %lld\n",2+23*yy+xx-1 ,24+23*yy);
		}
	}
	}
	else{
		no1=no;
		scanf("%lld",&no2);
		if(no1==0&&no2==0)
			break;
		if(no1==0||no2==0||no1==1)
			printf("No Number\n");
		else if((no1-2)%23==0)
		{
			yy=(no1-2)/23;
			xx=no2-23*yy;
			if(1<=xx && xx<=24)
			printf("%lld\n",yy*46+xx);
			else
				printf("No Number\n");


		}
		else if((no2-24)%23==0&&no1!=no2){
			yy=(no2-24)/23;
			xx=no1-1-yy*23+23;
			if(24<=xx&&xx<=45)
			printf("%lld\n",yy*46+xx);
			else
				printf("No Number\n");
		}
		else if((no1==no2)&&((no1-24)%23==0))
		{
			yy=(no1-24)/23+1;
			
			printf("%lld\n",yy*46);
		}
		else
			printf("No Number\n");
	}
	}
	// now what is the fucking trend ! < o.O > ? 
	// if it lies on vertical line (2+23*number,1+23*number) TO (2+23*number, 23+23*number)
	// if it lies on horizontal line (2+23*n,24+23*number) TO (24+23*number, 24+23*number)
	// I got it ! 
return 0;
}

