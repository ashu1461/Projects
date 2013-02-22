/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'easymathematics'
date->Sat Dec 15 23:56:40 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
	int no,k;
	scanf("%d %d",&no,&k);
//	int rem=no%k;
//	int number=no/k;
	int new = (2*(no+k*k))/(3*k*k+k);
	int rem = (2*(no+k*k))%(3*k*k+k);
	printf("%d %d\n",new,rem/2);
	if(rem!=0){
	int i;
	for(i=1;;i++)
		if(((new+1)*i*k+i*(i+1)/2)>rem)
			break;
	printf("here is the i %d\n",i);
	// bas i se phele i katam ho jaenge ! :D ! 
	}
	// what to do now ?
		
	}

return 0;
}

