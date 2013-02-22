/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'E_23_Stairs_pattern'
date->Thu Jun  7 05:58:18 IST 2012*/
#include<stdio.h>
int main()
{
	int x=2,y=1;
	int number=0;
	int flag=0;
	int i;
	for(i=0;i<10;i++){
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
	}
	int no;
/*	while(1){
	scanf("%d",&no);
	int xx=no%46;
	int yy=no/46;
	if(1<=xx&&xx<=23)
	{
		printf("%d,%d\n",2+23*yy,1+23*yy+xx-1);
	}
	else if(xx==0||(24<=xx&&xx<=45))
	{
		if(xx==0){
			printf("%d,%d\n",24+23*(yy-1),24+23*(yy-1));
		}
		else{
			xx=xx-23;
			printf("here %d\n",xx);
			printf("%d,%d\n",2+23*yy+xx-1,24+23*yy);
		}
	}
	}*/
	int no1,no2;
	int xx,yy;
	while(1)
	{
	scanf("%d %d",&no1,&no2);
		if((no1-2)%23==0)
		{
			yy=(no1-2)/23;
			xx=no2-23*yy;
			printf("%d\n",yy*46+xx);
		}
		else if((no2-24)%23==0){
			yy=(no1-24)/23;
			xx=no2-1-yy*23+23;
			printf("%d\n",yy*46+xx);
		}
		else if((no1==no2)&&(no1-24%23==0))
		{
			yy=(no1-24)/23+1;
			printf("%d\n",yy*46);
		}
		else
			printf("No Number\n");
	}
	// now what is the fucking trend ! < o.O > ? 
	// if it lies on vertical line (2+23*number,1+23*number) TO (2+23*number, 23+23*number)
	// if it lies on horizontal line (2+23*n,24+23*number) TO (24+23*number, 24+23*number)
	// I got it ! 
return 0;
}

