/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'musicalchair'
date->Sun Jun  3 12:44:50 IST 2012*/
#include<stdio.h>
int main()
{
	int n,d;
	while(1)
	{
	scanf("%d %d",&n,&d);
	if(n==0)
		return 0;
	// n is 5 and d is 3 ! 
	int total=n,i,start=0;
	int flag[n],no,counter,set,ans;
	for(i=0;i<n;i++)
		flag[i]=0;
	while(total!=1)
	{
//		printf("start is %d\n",start);
		if(total+1>=d)
		no=d%(total+1);
		else
			no=total;
		counter=0;
//		for(i=0;i<n;i++)
//			printf("%d ",flag[i]);
//			printf("\n");
//		printf("no total %d %d\n",no,total);	
		for(i=start;i<start+n;i++)
		{
			if(no==0)
			{
				set=start;
				flag[start]=1;
				total--;
				break;
			}
			if(flag[i%n]==0)
				counter++;
			if(counter==no)
			{
				set=i%n;
				flag[i%n]=1;
				total--;
				break;
			}
		}
//		printf("set is %d\n",set);
//		
		for(i=set;i<set+n;i++)
			if(flag[i%n]==0)
			{
				start=i%n;
			break;
			}
		if(total==1)
		{
			ans=start+1;
			break;
		}
	}
	printf("%d %d %d\n",n,d,ans);
	}
return 0;
}

