/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'sets'
date->Fri Jan  4 14:20:35 IST 2013*/
#include<stdio.h>
long long int greater[100000];
long long int less[100000];
long long int equal[100000];
long long int nequal[10000];
int compare_function(const void *a,const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	return *x - *y;
}                       

int main()
{
	// inequality will lie on either the greater than or the equal to identifiers :) 
	int cg=0,cl=0,ce=0,cne=0;
	// thats how we roll ! :D
	long long int a , b; 
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%lld %lld",&a,&b);
		if(a==1)
			greater[cg++]=b;
		else if(a==2)
			less[cl++]=b;
		else if(a==3)
			equal[ce++]=b;
		else
			nequal[cne++]=b;
	}
	qsort(greater,cg,sizeof(greater[0]),compare_function);
	qsort(less,cl,sizeof(less[0]),compare_function);
	qsort(equal,ce,sizeof(less[0]),compare_function);
	qsort(equal,cne,sizeof(less[0]),compare_function);
long long int ans,max=0,max1=0;
long long int i,j;
for(i=0;i<cg;i++)
	printf("%d ",greater[i]);
printf("\n over \n");
	for(i=0;i<cg;i++){
		max1=0;
		// check inequality for greater[i]+1;
		for(j=0;j<cl;j++)
			if((greater[i]+1)<less[j])
				max1++;
		for(j=0;j<cg;j++)
			if((greater[i]+1)>greater[j])
			{
		//		printf("here in greater %lld %lld\n",greater[i]+1,greater[j]);
				max1++;
			}
		for(j=0;j<ce;j++)
			if((greater[i]+1)==equal[j]){
		//		printf("here in equal %d \n",equal[j]);
				max1++;
			}
		for(j=0;j<cne;j++)
			if((greater[i]+1)!=nequal[j])
				max1++;
		if(max1>max){
			max=max1;
			ans=greater[i]+1;
		}
		else if(max1==max){
			if(ans<greater[i]+1)
				ans=greater[i]+1;
		}
	}
	for(i=0;i<ce;i++){
		max1=0;
		// check inequality for greater[i]+1;
		for(j=0;j<cl;j++)
			if((equal[i])<less[j])
				max1++;
		for(j=0;j<ce;j++)
			if((equal[i])==equal[j]){
		//		printf("here in equal2\n");
				max1++;
			}
		for(j=0;j<cg;j++)
			if((equal[i])>greater[j]){
		//		printf("here in greater2 ,%d\n",greater[j]);
				max1++;
			}
		for(j=0;j<cne;j++)
			if((equal[i])!=nequal[j])
				max1++;
		if(max1>max){
			max=max1;
			ans=equal[i];
		}
		else if(max1==max){
			if(ans>equal[i])
				ans=equal[i];
		}
	}
		max1=cl;
		// check inequality for greater[i]+1;
		for(j=0;j<ce;j++)
			if((0)==equal[j]){
				max1++;
			}
		for(j=0;j<cne;j++)
			if(0!=nequal[j])
				max1++;
		if(max1>max){
			max=max1;
			ans=equal[i];
		}
		else if(max1==max){
			if(ans>equal[i])
				ans=equal[i];
	}
//	printf("answer is %lld\n and maximum equalities satis %lld\n",ans,max);
	printf("%lld %lld\n",max,ans);
return 0;

}

