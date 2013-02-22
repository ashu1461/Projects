/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'MAXIUM_SUBSET'
date->Thu Jun  7 08:16:01 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int flag=0;
		long long int ans=-10000000000000000;
		long long int counter=0,counter1=0;
		int n;
		scanf("%d",&n);
		long long int no;
		while(n--){
		scanf("%lld",&no);
			if(no>0){
				if(flag==0){
				flag=1;
				ans=0;
				}
				ans=ans+no;
			}
			else if(no<0&&flag==0){
				if(no==ans){
				counter=(counter+1)%100000009;
				}
				else if(no>ans){
					counter=1;
					ans=no;
				}
			}
			else if(no==0){
				counter1=(counter1+1)%100000009;
			}
		}
		if(ans>0)
			counter=1+counter1;
		else if(ans<0&&counter1!=0){
			ans=0;
			counter=counter1;
		}
		printf("%lld %lld\n",ans,counter);
	}
return 0;
}

