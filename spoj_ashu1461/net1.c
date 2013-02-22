/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'adding_binary'
date->Sun Oct 28 15:18:27 IST 2012*/
#include<stdio.h>
#include<math.h>
int function()
int main()
{
	char A[100],B[100];
	scanf("%s %s",A,B);
	printf("%s %s\n",A,B);
	char S[100];
	int sta=strlen(A),stb=strlen(B);
	int i;
	int carry=0;
	int maxi=max(sta,stb);
	for(i=0;i<max;i++){
		if(A[i]=='0'&&B[i]=='0'&&carry==0){
			S[i]='0';
			carry=0;
		}
		else if(A[i]=='0'&&B[i]=='0'&&carry==1){
			S[i]='1';
			carry=0;
		}
		else if(A[i]=='0'&&B[i]=='1'&&carry==0){
			S[i]=1;
			carry=0;
		}
		else if(A[i]=='0'&&B[i]=='1'&&carry==1){
			S[i]=0;
			carry=1;
		}
		else if(A[i]=='1'&&B[i]=='0'&&carry==0){
			S[i]=1;
			carry=0;
		}
		else if(A[i]=='1'&&B[i]=='0'&&carry==1){
			S[i]=0;
			caarry=1;
		}
		else if(A[i]=='1'&&B[i]=='1'&&carry==0){
			S[i]=0;
		else if(A[i]=='1'&&B[i]=='1'&&carry==1)
			S[i]=0;
return 0;
}

