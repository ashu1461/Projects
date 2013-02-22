#include<stdio.h>
#include<vector>
using namespace std;
vector<int> a[2000];
int print(int k){
	int i;
	for(i=0;i<a[k].size();i++){
		printf("%d ",a[k][i]);
	}
	printf("\n");
}
int main(){
	int c,b;
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d %d",&c,&b);
		a[c].push_back(b);
		a[b].push_back(c);
	}
	for(i=0;i<n+1;i++)
		print(i);

}
