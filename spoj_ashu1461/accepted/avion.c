/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'AVION1'
date->Tue Jun  5 10:54:05 IST 2012*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	int flag=0;
	for(j=0;j<5;j++){
		char s[1000];
		scanf("%s",s);
		for(i=0;i<strlen(s)-1;i++){
			if(s[i]=='F'&&s[i+1]=='B'&&s[i+2]=='I'){
				printf("%d ",j+1);
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
		printf("HE GOT AWAY!");
	printf("\n");
return 0;
}

