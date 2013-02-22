/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'common_permutation'
date->Wed Jun  6 13:44:53 IST 2012*/
#include<stdio.h>
#include<string.h>
int minimum(int a,int b){
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	char a[10000],b[10000];
	int i,j;
	while(scanf("%s %s",a,b)!=EOF){
		int A[26],B[26];
		for(i=0;i<26;i++){
			A[i]=0;
			B[i]=0;
		}
		for(i=0;i<strlen(a);i++){
			A[(int)a[i]-97]++;
		}
		for(i=0;i<strlen(b);i++){
			B[(int)b[i]-97]++;
		}
		for(i=0;i<26;i++){
			int min=minimum(A[i],B[i]);
			for(j=0;j<min;j++){
				printf("%c",i+97);
			}
		}
		printf("\n");

	}
return 0;
}

