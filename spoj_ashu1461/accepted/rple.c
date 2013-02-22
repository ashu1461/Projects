/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'Espioage'
date->Sat Jun  9 06:37:51 IST 2012*/
#include<stdio.h>
#include<stdlib.h>
struct list{
	int rno;
	struct list* next;
};
typedef struct list q;
void insert(q*, int no);
int search(q*,int no);
int main()
{

	int test;
	scanf("%d",&test);
	int counter=0;
	q* start;
	start=(q*)malloc(sizeof(q));
	start->next=NULL;
	while(test--){
		int n,r;
		int x,y;
		int flag=0;
		scanf("%d %d",&n,&r);
		while(r--){
			scanf("%d %d",&x,&y);
			if(flag!=1){
			if(search(start,y)==1){
			flag=1;
			}
			else
				insert(start,x);
			}
		}
		if(flag==0){
			printf("Scenario #%d: spying\n",++counter);
		}
		else
			printf("Scenario #%d: spied\n",++counter);
	}
return 0;
}
int search(q* start,int n){
	start=start->next;
	while(start!=NULL){
		if(start->rno==n)
			return 1;
		start=start->next;
	}
	return 0;
}
void insert(q* start,int n){
	while(start->next!=NULL)
		start=start->next;
	start->next=(q*)malloc(sizeof(q));
	start=start->next;
	start->rno=n;
	start->next=NULL;
}

