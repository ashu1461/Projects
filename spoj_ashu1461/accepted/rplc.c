/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'coke_madness'
date->Thu Jun  7 05:47:04 IST 2012*/
#include<stdio.h>
int main()
{
	long long int test,sum,ans,no;
	scanf("%lld",&test);
	long long int j;
	for(j=0;j<test;j++){
		scanf("%lld",&no);
		int i,A[no];
		for(i=0;i<no;i++){
			scanf("%d",&A[i]);
		}
		ans=A[0];
		sum=0;
		for(i=0;i<no;i++){
			sum=sum+A[i];
			if(sum<ans){
				ans=sum;
			}
		}
			
		if(ans>0)
			ans=1;
		else
			ans=-ans+1;
		printf("Scenario #%lld: %lld\n",j+1,ans);
	}
return 0;
}

