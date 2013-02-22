#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	// what the hell nw ?
	int test,i;
	scanf("%d",&test);
	char s[100];
	while(test--){
		scanf("%s",s);
		long long int sum=1,counter=1;
		char c = 's';
		for(i=0;i<strlen(s);i++){
			if(s[i]==c)
				counter++;
			else{
				c=s[i];
				if(counter>1){
				sum = sum*pow(2,counter-1);
				counter=1;
				}
			}
		}
		if(counter>1)
				sum = sum*pow(2,counter-1);
		if(sum!=0)
		printf("%lld\n",sum);
		else printf("1\n");

	}
	
}
