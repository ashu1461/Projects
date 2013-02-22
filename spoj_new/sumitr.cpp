#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
	int n,a,k,t,i,A[102],z; cin >> n ; while(n--){cin >> a; k=1; memset(A,0,sizeof(A)); while(a--){ 
		z=-1;
		for(int i=0;i<k;i++){
			cin >> t;
			A[i]=A[i]+t;
		}k++;}
		for(a=0;a<k-1;a++){if(A[a]>z)z=A[a];}
		cout<<z<<"\n";
		}}
