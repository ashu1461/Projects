/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'Seinfield-Greedy-stack'
date->Thu Dec  6 16:36:52 IST 2012*/
#include<stdio.h>
#include<string.h>

int main()
{
	int counter=0;
	char s[2002];
	while(1){
		counter++;
	
	int top=0;
	scanf("%s",s);
	int i,ans=0;
	char stack[2002];
	if(s[0]=='-')
		return 0;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='{'){
			stack[top]='{';
			top++;
		}
		else
			if(top!=0){
				top--;
			}
			else{
				ans=ans+1;
				stack[top]='{';
				top++;
			}

	}
	ans=ans+top/2;
	printf("%d. %d\n",counter,ans);
	}
return 0;
}
