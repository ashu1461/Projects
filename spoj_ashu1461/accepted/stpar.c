#include<stdio.h>
int main()
{
	while(1)
{

	int n;
	scanf("%d",&n);
	if(n==0)
		return 0;
	int A[n];
	int B[n];
	int flag=1;
	int counter=0,i,j;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	// if a[i] is not equal to flag move in B[i] increment counter
	// else if a[i]==flag 
	// check for b[counter] and keep incrementing flag and decrementing counter
	// till end if flag!=n and counter!=0 print no else print yes
	for(i=0;i<n;i++)
	{
		if(A[i]==flag)
		{
			flag++;
			while(counter>0 && B[counter-1]==flag)
			{
				flag++;
				counter--;
			}
		}
		else
		{
			B[counter]=A[i];
			counter++;
		}
	}
	if(counter!=0||flag!=n+1)
		printf("no\n");
	else 
		printf("yes\n");
}
	return 0;
}
