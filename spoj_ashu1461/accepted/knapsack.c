/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'dynamic_programming'
date->Tue Jun  5 02:26:44 IST 2012*/
#include<stdio.h>
int max(int a,int b){
	if(a>=b)
		return a;
	else
	return b;
}
int main()
{
	int W,n;
	scanf("%d %d",&W,&n);
	int w[n+1],v[n+1],i,j;
	for(i=1;i<=n;i++){
		scanf("%d %d",&w[i],&v[i]);
	}
	// w[i] has the weight and V[i] hast the value;
	// b is the number of elements and a is the total weight
	int V[n+1][W+1];
	for(i=0;i<=W;i++){
		V[0][i]=0;
	}
//	for(i=0;i<=n;i++){
//		V[i][0]=0;
//	}
	for(i=1;i<=n;i++){
		for(j=0;j<=W;j++){
			if(w[i]<=j){
				V[i][j]=max(V[i-1][j],v[i]+V[i-1][j-w[i]]);
			}
			else
				V[i][j]=V[i-1][j];
		}
	}
//	for(i=0;i<=n;i++){
//		for(j=0;j<=W;j++)
//			printf("%d ",V[i][j]);
//		printf("\n");
//	}
	printf("%d\n",V[n][W]);

return 0;
}

