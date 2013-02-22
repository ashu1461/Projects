#include<stdlib.h>
#include<stdio.h>
struct list
{
	int rno;
	struct list *next;
};
typedef struct list q;
void insert(q*,int );
int find(q*,int);
int main()
{
	int test,i;
	scanf("%d",&test);
	while(test>0)
	{
	q* start[10000];
	int no,n;
	scanf("%d %d",&no,&n);
// where no is the number of students and n is the no of tests given.
	for(i=0;i<no;i++)
	{
		start[i]=(q*)malloc(sizeof(q));
		start[i]->next=NULL;
	}
	int a,b;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		// a is the student name and b is the id 
		printf("finding in %d the number %d\n",a,b);
		if(find(start[a-1],b==1))
		{
			printf("No\n");
			return ;
		}

		else
		{
			printf("inseting in %d the number %d\n",a,b);
			insert(start[a-1],b);
		}
	}
	printf("Yes\n");
	test--;
	}
	return 0;
}
void insert(q* start,int no)
{
	while(start->next!=NULL)
		start=start->next;
	start->next=(q*)malloc(sizeof(q));
	start=start->next;
	start->rno=no;
	start->next=NULL;
}
int  find(q* start,int no)
{
	while(start->next!=NULL&&start->next->rno!=no)
		start=start->next;
	if(start->next==NULL&&start->rno!=no)
		return 0;
	else
		printf("%d",start->next->rno);
		return 1;
}
