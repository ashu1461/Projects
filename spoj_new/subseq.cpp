#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int sum[1000001];
int main(){
	int test;
	int no;
	int i;
	int temp;
	long long int ans=0;
	scanf("%d",&test);
	while(test--){
	map <int,int> mymap;
	scanf("%d",&no);
	mymap[0]=1;
	ans=0;
	sum[0]=0;
	for(i=1;i<=no;i++){
		scanf("%d",&temp);
//		cout << "jere is " << temp << "\n";
		sum[i]=sum[i-1]+temp;
//			printf("hello rock the world %d\n",mymap[sum[i]-47]);
//		if(mymap.count(sum[i]-47)>0){
//			printf("rock the world %d\n",mymap[sum[i]-47]);
		ans=ans+mymap[sum[i]-47];
//		}
//		if(mymap.count(sum[i])>0)
		mymap[sum[i]]++;
//		else mymap[sum[i]]=1;
		// yo baby yo ! :D
	}
//	for(i=1;i<=no;i++){
//	 cout << " " << sum[i] ;
//	}
	printf("%lld",ans);
	cout << "\n";
	}
}
