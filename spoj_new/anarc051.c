/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'NO_OF_POLYNOMIALS'
  date->Thu Dec  6 18:41:43 IST 2012*/
#include<stdio.h>
#include<string.h>
	int A[2000][2000];
int main()
{
	int a,b;
	int i,j;
	int k;
	char s[1002];
//		printf("here we are \n");

	while(1){
		memset(A, 0, sizeof(A[0][0]) * 2000 * 2000);
//		for(i=0;i<2000;i++)
//			for(j=0;j<2000;j++)
//				A[i][j]=0;
		scanf("%s",s);
		// as there are no overlaps ! :D
//		printf("here we are \n");
		A[1000][1000]=1;
		a=1000;
		b=1000;
		int ans=0;
		if(s[0]=='Q')
			return 0;
//			printf("locations are %d %d \n",a,b);
//		printf("%s",s);
		for(k=0;k<strlen(s);k++){
			if(s[k]=='U'){
				b=b+1;
				if(A[a][b]==1)
					ans++;
				A[a][b]=1;
			}
			else if(s[k]=='D'){
				b=b-1;
				if(A[a][b]==1)
					ans++;
				A[a][b]=1;
			}
			else	if(s[k]=='L'){
				a=a-1;
				if(A[a][b]==1)
					ans++;
				A[a][b]=1;
			}
			else if(s[k]=='R'){
				a=a+1;
				if(A[a][b]==1)
					ans++;
				A[a][b]=1;
			}
//			printf("locations are %d %d \n",a,b);
		}
		// now as it is over let us print the answer ! 
		printf("%d\n",ans);
	}
	return 0;
}

