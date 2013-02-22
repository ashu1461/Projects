#include<stdio.h>
#include<stdlib.h>
struct list
{
	int rno;
	struct list *next;
};
typedef struct list q;
void insert(q* start,int no)
{
	while(start!=NULL)
		start=start->next;
	start=(q*)malloc(sizeof(q));
	start->rno=no;
	start->next=NULL;
}
int find(q* start,int no)
{
	while(start!=NULL&&start->rno!=no)
	{
		start=start->next;
	}
	if(start==NULL)
		return 0;
	else
		return 1;
}
void print(q* start)
{
	while(start!=NULL)
	printf("%d ",start->rno);
	printf("\n");
}
int main()
{
	int n;
	q*start=NULL;
	while(1)
	{
		scanf("%d",&n);
		printf("%d\n",find(start,n));
		print(start);
		insert(start,n);
	}

}
