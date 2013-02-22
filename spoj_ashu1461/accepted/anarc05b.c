/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'double_helix'
date->Mon Jun  4 14:06:01 IST 2012*/
#include<stdio.h>
int main()
{
	int a,b,i;
		int A[100005];
		int B[100005];
		int flag[100005];
		int flag2[100005];
	while(1){
		scanf("%d",&a);
		if(a==0)
			break;
		for(i=0;i<a;i++)
			scanf("%d",&A[i]);
		scanf("%d",&b);
		int count=0,bb;
		int search=0,j;
		int last=-1;
//		for(i=0;i<b;i++){
//			flag[i]=-1;
//			flag2[i]=-1;
//		}
		for(i=0;i<b;i++){
			bb=-1;
			scanf("%d",&B[i]);
			for(j=search;j<a;j++)
				if(B[i]==A[j]){
					flag[count]=j;
					flag2[count]=i;
					count++;
					bb=1;
					search=j+1;
					break;
			}
			if(bb==-1)
				search=0;
		}
		
	//	for(i=0;i<count;i++)
	//		printf("%d -> %d\n",flag[i],flag2[i]);
	//	printf("\n");
	long long int ans1=0,ans2=0,ans=0;
	if(count!=0){
		for(j=0;j<=flag[0];j++)
			ans1=ans1+A[j];
		for(j=0;j<=flag2[0];j++)
			ans2=ans2+B[j];
		if(ans1>ans2)
			ans=ans1;
		else
			ans=ans2;
//		printf("before %d\n",ans);
		for(i=1;i<count;i++){
			ans1=0,ans2=0;
//			printf("%d -> %d\n",flag[i],flag2[i]);
			for(j=flag[i-1]+1;j<=flag[i];j++){
				ans1=ans1+A[j];
			}
			for(j=flag2[i-1]+1;j<=flag2[i];j++){
				ans2=ans2+B[j];
			}
			if(ans1>ans2)
				ans=ans+ans1;
			else
				ans=ans+ans2;
//			printf("after %d %d %d\n",ans1,ans2,ans);
		}
		ans1=0,ans2=0;
		for(j=flag[count-1]+1;j<a;j++)
			ans1=ans1+A[j];
		for(j=flag2[count-1]+1;j<b;j++)
			ans2=ans2+B[j];
		if(ans1>ans2)
			ans=ans1+ans;
		else
			ans=ans2+ans;
//		printf("%d %d %d\n",ans1,ans2,ans);
		printf("%lld",ans);
	}
	else{
		for(i=0;i<a;i++){
			ans1=ans1+A[i];
		}
	for(i=0;i<b;i++)
		ans2=ans2+B[i];
	if(ans1>ans2)
		ans=ans1;
	else
		ans=ans2;
	printf("%lld",ans);
	}
	printf("\n");
	}
return 0;
}

