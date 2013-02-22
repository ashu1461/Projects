/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'girls_and_boys_Easy'
date->Fri Dec  7 23:18:02 IST 2012*/
#include<stdio.h>
int main()
{
	int a,b;
	while(1){
		scanf("%d %d",&a,&b);
		if(a==-1)
			return 0;
		int temp;
		if(a<b){
			temp=a;
			a=b;
			b=temp;
		}
		// now a is the larger number ! 
		if(b==0||a==b)
			printf("%d\n",a);
		else if(a%(b+1)==0)
			printf("%d\n",a/(b+1));
		else
			printf("%d\n",a/(b+1)+1);
	}
return 0;
}

