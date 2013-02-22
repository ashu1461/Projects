/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'sets'
date->Fri Jan  4 14:20:35 IST 2013*/
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
int compare_function(const void *a,const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	return *x - *y;
}                       
int main()
{
	// inequality will lie on either the greater than or the equal to identifiers :) 
	map <long long int , int > mymap;
	map <long long int , int > mymap1;
	int cg=0,cl=0,ce=0,cne=0;
	// thats how we roll ! :D
long long int greater[100000];
long long int less[100000];
long long int equal[100000];
	long long int a , b; 
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%lld %lld",&a,&b);
		if(a==1)
			greater[cg++]=b;
		else if(a==2)
			less[cl++]=b;
		else if(a==3){
			mymap[b]=1;
			equal[ce++]=b;
		}
		else{
			mymap1[b]=1;
			cne++;
		}
	}
	qsort(greater,cg,sizeof(greater[0]),compare_function);
	qsort(less,cl,sizeof(less[0]),compare_function);
	qsort(equal,ce,sizeof(less[0]),compare_function);
	qsort(equal,cne,sizeof(less[0]),compare_function);
	long long int ans,max=0,max1=0;
	long long int i,j;/*
	for(i=0;i<cl;i++)
	printf("%lld ",less[i]);
	printf("\nless over \n");
	for(i=0;i<cg;i++)
	printf("%lld ",greater[i]);
	printf("\n greater over \n");
	for(i=0;i<ce;i++)
	printf("%lld ",equal[i]);
	printf("\n equal over \n");*/
	int sl=0,sg=0,sne=0;
	for(i=0;i<cg;i++){
		max1=i+cne+1;
		// check inequality for greater[i]+1;
		for(j=sl;j<cl;j++)
			if((greater[i]+1)<less[j]){
//				printf("here int he less loop\n");
				max1=max1+cl-j;
				sl=j+1;
				break;
			}
		if(mymap.count(greater[i]+1)>0)
			max1++;
		if(mymap1.count(greater[i]+1)>0)
			max1--;
		if(max1>max){
			max=max1;
			ans=greater[i]+1;
		}
		else if(max1==max){
			if(ans<greater[i]+1)
				ans=greater[i]+1;
		}
//		printf("int he iterative loop %d\n",max1);
	}
	sl=0,sg=0;
	for(i=0;i<ce;i++){
		max1=1+cne;
		// check inequality for greater[i]+1;
		if(mymap1.count(equal[i])>0)
			max1--;
		for(j=sl;j<cl;j++)
			if((equal[i])<less[j]){
				max1=max1+cl-j;
				sl=j+1;
				break;
			}
		for(j=sg;j<cg;j++)
			if((greater[j]>equal[i])){
//			printf("here in greater2 ,%d\n",greater[j]);
				max1=max1+j+1;
				sg=j+1;
				break;
			}
		if(max1>max){
			max=max1;
			ans=equal[i];
		}
		else if(max1==max){
			if(ans>equal[i])
				ans=equal[i];
		}
	}
//	printf("Here is the  %lld\n",ans);
		max1=cl+cne;
		if(mymap.count(0)>0)
			max1++;
		if(mymap1.count(0)>0)
			max1--;
		// check inequality for greater[i]+1;
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

