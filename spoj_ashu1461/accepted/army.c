/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'army_strength'
date->Mon Jun  4 01:19:50 IST 2012*/
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d %d",&a,&b);
		int maxa=-1,maxb=-1;
		int i;
		int no;
		for(i=0;i<a;i++)
		{
			scanf("%d",&no);
			if(no>=maxa)
				maxa=no;
		}
		for(i=0;i<b;i++)
		{
			scanf("%d",&no);
			if(no>=maxb)
				maxb=no;
		}
		if(maxa>=maxb)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}
return 0;
}

