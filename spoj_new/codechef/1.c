#include<stdio.h>
#include<string.h>
int main(){
	map <string,int> range;
	char A[100],B[100];
	scanf("%s %s",A,B);
	if(strcmp(A,B)>0)
		printf("A is greater than B\n");
	else if(strcmp(A,B)<0)
		printf("B is greater than A\n");
	else
		printf("A is===  B\n");
	// just print the lexorgraphic sequence !! 
		
	
}
