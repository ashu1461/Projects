/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'adding_binary'
date->Sun Oct 28 15:18:27 IST 2012*/
#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if(a<b)
	return a;
	return b;
}
int main()
{
	int final=1;
	int n;
	scanf("%d\n",&n);
	int j;
	for(j=0;j<n;j++){
	char A[100],B[100];
	scanf("%s %s",A,B);
	int S[100];
	int sta=strlen(A),stb=strlen(B);
	int i;
	int a[1000];
	int b[1000];
	int counter=0;
	for(i=sta-1;i>=0;i--){
		if(A[i]=='0')
			a[counter]=0;
		else
			a[counter]=1;
		counter++;
	}
	counter=0;
	for(i=stb-1;i>=0;i--){
		if(B[i]=='0')
			b[counter]=0;
		else
			b[counter]=1;
		counter++;
	}
	int carry=0;
	int maxi=max(sta,stb);
	for(i=0;i<maxi;i++){
		S[i]=carry^a[i]^b[i];
		carry=(a[i]&carry)|(b[i]&carry)|(a[i]&b[i]);
	}
	int maximum;
	if(maxi==sta){
		maximum=stb;
		for(i=maxi;i<stb;i++){
			S[i]=carry^b[i];
			carry=carry&b[i];
		}
	}
	else{
		maximum=sta;
		for(i=maxi;i<sta;i++){
			S[i]=carry^a[i];
			carry=carry&a[i];
		}
	}
	int torreto=-99;
	printf("%d ",j+1);
	if(carry==1){
		printf("1");
		torreto=maximum-1;
	}
	else{
	for(i=maximum-1;i>=0;i--){
		if(S[i]!=0){
			torreto=i;
			break;
		}
	}
	}
	if(torreto==-99){
		printf("0");
	}
	else{
	for(i=torreto;i>=0;i--)
		printf("%d",S[i]);
	}
	printf("\n");
	}
return 0;
}

