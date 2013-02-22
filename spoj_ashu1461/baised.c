/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'biased_standing'
date->Tue Jun  5 11:24:14 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int no;
		scanf("%d",&no);
		int A[no+1],i;
		for(i=1;i<=no;i++)
			A[i]=0;
		char s[100000];
		int n;
		for(i=0;i<no;i++){
			scanf("%s %d",s,&n);
			A[n]++;
		}
		int counter=1;
		int ans=0;
		for(i=1;i<=no;i++){
			while(A[i]--){
				ans=ans+abs(i-counter);
				counter++;
			}
		}
		printf("%d\n",ans);
	}
return 0;
}

