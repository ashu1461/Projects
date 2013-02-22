/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'bipartite_graph'
date->Fri Dec  7 15:02:10 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	int counter=0;
	scanf("%d",&test);
	while(test--){
		counter++;
		int n ;
		long b;
		scanf("%d %ld",&n,&b);
		int A[n];
		// this will be the color array ! 
		int i ;
		for(i=0;i<n;i++)
			A[i]=0;
		// let 0 stand for blue
		int x,y;
		scanf("%d %d",&x,&y);
		A[x]=1;
		A[y]=1;
		b--;
		int flag=1;
		while(b--){
			scanf("%d %d",&x,&y);
			if((A[x]==1&&A[y]==0)||(A[y]==1&&A[x]==0)){
				A[x]=1;
				A[y]=1;
				flag=0;
			}
		}
		int center=0;
		if(flag==0)
		for(i=0;i<n;i++){
			if(A[i]==0)
			{
				center=1;
				break;
			}
		}
		if(flag==0&&center==1)
			printf("Scenario #%d:No suspicious bugs found!\n",counter);
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n",counter);
	}
return 0;
}

