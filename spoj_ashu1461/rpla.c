/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'Answer_The_Boss'
date->Sat Jun  9 07:25:51 IST 2012*/
#include<stdio.h>
struct data{
	int counter;
	int number;
};
struct data rec[1002];
int A[1002][1002];
int n;
int function(int num){
	int answer=0;
	int flag=0;
	int i;
	for(i=0;i<n;i++){
		if(A[num][i]==1){
//			printf("calling from %d to %d\n",num,i);
			answer=answer+function(i);
			flag=1;
		}

	}
	rec[num].counter=answer;
	if(flag==0)
	return 1;
	else 
	return answer;
}
int main()
{
	int r;
	scanf("%d %d",&n,&r);
	int j,i;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			A[i][j]=0;
	}
	for(i=0;i<n;i++){
		rec[i].counter=0;
		rec[i].number=i;
	}
	
	int x,y;
	for(i=0;i<r;i++){
		scanf("%d %d",&x,&y);
		A[y][x]=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	function(0);
	for(i=0;i<n;i++)
		printf("%d ",rec[i].counter);
	printf("\n");
	// now we just have to sort the numbers and if any of the numbers are equal print them according to the 
	int max;
	struct data b[1];
	for(i=0;i<n;i++){
		max=i;
		for(j=i;j<n;j++)
			if(rec[j].counter>=rec[max].counter){
				max=j;
			}
		b[0]=rec[max];
		rec[max]=rec[i];
		rec[i]=b[0];
	}
	for(i=0;i<n;i++)
		printf("%d ",rec[i].counter);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",rec[i].number);
	printf("\n");
return 0;
}
