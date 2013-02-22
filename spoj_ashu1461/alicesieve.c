/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'ALICESIEVE'
date->Tue Jun  5 09:47:15 IST 2012*/
#include<stdio.h>
int main()
{
	int prime[1000001];
	int i,j;
	int count[1000001];
	for(i=0;i<1000001;i++){
		count[i]=0;
		prime[i]=1;
	}
	for(i=2;i<1000001;i++){
		if(prime[i]==0)
			count[i]=count[i-1];
		else{
			for(j=2*i;j<1000001;j=j+i){
				prime[j]=0;
			}
			count[i]=count[i-1]+1;
		}
		
	}
	int test;
	scanf("%d",&test);
	while(test--){

		int no;
		scanf("%d",&no);
		printf("%d\n",count[no]+!prime[no]);
	}

return 0;
}

