/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'map_implementation'
date->Mon Dec 24 05:26:49 IST 2012*/
#include<stdio.h>
#include<string.h>
long long int A[1111111];
long long int B[1111111];
int main()
{
	int n;
	int no;
	scanf("%d",&no);
	memset(A,-1,sizeof(A));
	memset(B,0,sizeof(A));
	long long int i,x;
	for(i=0;i<no;i++){
		scanf("%lld",&x);
		if(A[x]==-1){
//			printf("here ---> %lld\n",x);
			B[i]=-1;
			A[x]=i;	
		}
		else{
//			printf("2.here ---> %lld\n",x);
			B[i]=A[x];
			A[x]=i;
		}
	}
//	for(i=0;i<no;i++)
//		printf("%lld ",B[i]);
//	printf("\n");
	long long int qu,a,b,ans=0;
	scanf("%lld",&qu);
	while(qu--){
		scanf("%lld %lld",&a,&b);
		ans=b-a+1;
		for(i=a-1;i<b;i++)
			if((a-1)<=B[i]&&B[i]<=b-1)
				ans--;
	printf("%lld\n",ans);
	}
//	printf("\n");
	return 0;
}

