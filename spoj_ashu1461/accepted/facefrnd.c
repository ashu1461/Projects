#include<stdio.h>
#include<stdlib.h>
struct list
{
	int rno;
	struct list *next;
};
typedef struct list q;
void insert(q*,int);
int print(q*);
int delete(q*,int );
q* reverse(q*);
int main()
{	
	int n;
	q *start;
	start=(q*)malloc(sizeof(q));
	start->next=NULL;
	q* start2;
	start2=(q*)malloc(sizeof(q));
	scanf("%d",&n);
	int no;
	while(n--)
	{
			scanf("%d",&no);
			insert(start2,no);
			scanf("%d",&no);
			int noo;
			while(no--)
			{
				scanf("%d",&noo);
				if(delete(start,noo)==0)
				insert(start,noo);
			}
	}
	int counter=0;
	start2=start2->next;
	while(start2!=NULL)
	{
		if(delete(start,start2->rno)==1)
				counter++;
		start2=start2->next;
	}
	printf("%d\n",print(start)-counter);
	return 0;
	
}
void insert(q *start,int n)
{
	while(start->next!=NULL)
		start=start->next;
	start->next=(q*)malloc(sizeof(q));
	start=start->next;
	start->rno=n;
	start->next=NULL;
}
int  print(q *start)
{
	start=start->next;
	int counter=0;
	while(start!=NULL)
	{
		counter++;
//		printf("%d ",start->rno);
		start=start->next;
	}
	return counter;
}
int delete(q *start,int n){	
	start=start->next;
	while(start!=NULL)
	{
	//	printf("in here with %d %d\n",start->rno,n);
		if(start->rno==n)
			return 1;
		start=start->next;
	}
	return 0; 	
}
