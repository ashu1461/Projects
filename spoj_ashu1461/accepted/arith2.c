/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'simple_arithmetics'
  date->Tue Jun  5 10:37:50 IST 2012*/
#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		long long int ans=0,no;
		scanf("%lld",&ans);
//		printf("ans is %lld\n",ans);
		char c;
		int flag=0;
		while(1){
			scanf("%c",&c);
			switch(c){
				case '+':
					{
						scanf("%lld",&no);
						ans=ans+no;
						break;
					}
				case '-':
					{
						scanf("%lld",&no);
						ans=ans-no;
						break;
					}
				case '*':
					{
						scanf("%lld",&no);
						ans=ans*no;
						break;
					}
				case '/':
					{
						scanf("%lld",&no);
						ans=ans/no;
						break;

					}
				case '=':
					{
						printf("%lld\n",ans);
						flag=1;
					}
			}
			if(flag==1)
				break;
		}
	}
	return 0;
}

