/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'implementint_data_structure'
date->Sat Dec 22 12:21:36 IST 2012*/
#include<stdio.h>
struct data{
	int start;
	int end;
	int add;
};
typedef struct data q;
q ashu[100002];
int main()
{
	int test;
	scanf("%d",&test);
	int n,co,a,b,c,d,counter=0,i,p,q;
	long long int sum;
	while(test--){
		counter=0;
		scanf("%d %d",&n,&co);

		while(co--){
			scanf("%d",&a);
			if(a==0){
				scanf("%d %d %d",&b,&c,&d);
				ashu[counter].start=b;
				ashu[counter].end=c;
				ashu[counter].add=d;
				counter++;
			}
			if(a==1){
				sum=0;
				scanf("%d %d",&b,&c);
				for(i=0;i<counter;i++){
//					printf("%d %d %d\n",ashu[i].start,ashu[i].end,ashu[i].add);
					if(b<ashu[i].start)
						p=ashu[i].start;
					else
						p=b;
					if(c>ashu[i].end)
						q=ashu[i].end;
					else
						q=c;
			// now what ?? 
					if(q>=p){
//				printf("here we are %d %d\n",q-p+1,ashu[i].add);
					sum=sum+(q-p+1)*ashu[i].add;
					}
				}
				printf("%lld\n",sum);
			}
		}
	}
return 0;
}

