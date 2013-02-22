/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'brackets'
date->Mon Jun  4 09:48:43 IST 2012*/
#include<stdio.h>
#include<string.h>
int flag,i;
int function(char *s){
	int i,flag=0;
		for(i=0;i<strlen(s);i++){
			if(s[i]=='(')
				flag++;
			else
				flag--;
			if(flag<0){
				return 0;
			}
		}
		if(flag>0)
			return 0;
		else
			return 1;
}
int main()
{
	for(i=0;i<10;i++){
		printf("TEST %d:\n",i+1);
	int n;
	char s[1000000];
	scanf("%d",&n);
	scanf("%s",s);
	int test;
	scanf("%d",&test);
	int no;
	while(test--){
		scanf("%d",&no);
		if(no==0){
			if(function(s)==0)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else{
			if(s[no-1]==')'){
				s[no-1]='(';
			}
			else{
				s[no-1]=')';
			}
		}
	}
	}
return 0;
}

