/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'glassy_beads'
date->Mon Jun  4 08:54:28 IST 2012*/
#include<string.h>
#include<stdio.h>
int main()
{
	int test,i;
	scanf("%d",&test);
	while(test--){
		char s[100000];
		char ans[100000];
		scanf("%s",s);
		int sta=strlen(s);
		for(i=0;i<sta;i++){
			s[sta+i]=s[i];
		}
		s[2*sta]=0;
		// breaks the string at 2*sta;
		strcpy(ans,s);
		ans[sta]=0;
		int ans1=0;
		// breaks the string at sta;
		for(i=1;i<sta;i++){
//			printf("ans s i %s %s %d\n",ans,s,i);
			if(strcmp(ans,s+i)>0){
				strcpy(ans,s+i);
				ans[sta]=0;
				ans1=i;
			}
		}
		printf("%d\n",ans1+1);
	}

return 0;
}

