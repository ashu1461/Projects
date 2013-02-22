/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'database'
date->Fri Jun  8 21:58:27 IST 2012*/
#include<stdio.h>
#include<stdlib.h>
struct list{
	int rno;
	struct list* next;
};
typedef struct list q;
void insert(q*,int no);
int search(q*,int no);
void print(q*);
int main()
{
	int test;
	scanf("%d",&test);
	int counter=0;
	q *start[10000];
	while(test--){
		printf("Scenario #%d: ",++counter);
	int n,r;
	scanf("%d %d",&n,&r);
	int i;
	for(i=0;i<n+1;i++){
		start[i]=(q*)malloc(sizeof(q));
		start[i]->next=NULL;
	}
	int no,c,flag=0;
	for(i=0;i<r;i++){
		scanf("%d %d",&no,&c);
		if(flag==0){
		if(search(start[no-1],c)==1){
		printf("impossible\n");
		flag=1;
		}
		else
			insert(start[no-1],c);
		}
	}
	if(flag==0)
	printf("possible\n");
	}
return 0;
}
int search(q *start,int n){
	start=start->next;
	while(start!=NULL){
		if(start->rno==n)
			return 1;
		start=start->next;
	}
	return 0;
}
void insert(q*start ,int n){
	while(start->next!=NULL)
		start=start->next;
	start->next=(q*)malloc(sizeof(q));
	start=start->next;
	start->rno=n;
	start->next=NULL;
}
