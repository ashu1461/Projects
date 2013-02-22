#include <stdio.h>
#include <string.h>
char ans[100000], s[100000];
int main(){
	int t; scanf("%d", &t);
	int i;
	while(t-- && scanf("%s", s) == 1){
		int idx = 0, n = strlen(s);
		for(i=0; i < n; ++i) s[n + i] = s[i];
		s[2*n] = 0;
		strcpy(ans, s); ans[n] = 0;
		for(i = 1; i < n; ++i){
			printf("ans s i %s %s %d\n",ans,s,i);
			if(strcmp(ans, s + i) > 0){
				strcpy(ans, s + i);
				ans[n] = 0;
				idx = i;
			}
		}
		printf("%d\n", idx + 1);
	}
	return 0;
}
