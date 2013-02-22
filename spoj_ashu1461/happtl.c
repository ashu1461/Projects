/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'happy_telephones'
date->Mon Jun  4 01:47:59 IST 2012*/
#include<stdio.h>
int function(int,int,int,int);
int main()
{
	 int m1,m2,i,j,a,b;
	 while(1)
	 {
		 scanf("%d %d",&m1,&m2);
		 if(m1==0)
			 break;
		 int A[m1],B[m1],C[m2],D[m2];
		 for(i=0;i<m1;i++)
		 {
			 scanf("%d %d %d %d",&a,&b,&A[i],&B[i]);
		 }
		 for(i=0;i<m2;i++)
			 scanf("%d %d\n",&C[i],&D[i]);
		 int counter=0,flag=0;
		 int k;
		 for(j=0;j<m2;j++)
		 {
			 counter=0;
			 for(i=0;i<m1;i++)
			 {	
				if(function(A[i],B[i],C[j],D[j])==1)
					counter++;
			 }
			 printf("%d\n",counter);
		 }
		
	

	 }
return 0;
}
int function(int A,int B,int C,int D){
	int k;
for(k=C;k<=C+D;k++)
{
	if(k>=A && k<A+B)
	{
		return 1;
	}
}
return 0;
}
