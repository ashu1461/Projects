#include <stdio.h>
int main(){
	// where the mod variable should be used 
	int d;
	char c;
	while(1)
	{
		scanf("%d%c",&d,&c);
		if(c=='\n'){
			printf("one");
		}
		else{
			scanf("%d",&d);
			printf("second d is %d\n",d);
		}
	}
		/*		long long int len,m;
		scanf("%lld %lld", &len,&m);
		int A[len], prefixSum[len],subsum;
		int i,j;
		for(i = 0; i < len; i++) {
			scanf("%d",&A[i]);
		}
		prefixSum[0] = A[0];
		for(i = 1; i < len; i++) {
			prefixSum[i] = prefixSum[i-1] + A[i];
		}
		int max = -999999;
		int beg = 0 ;
		int end = 0;
		for(i = 0; i < len; i++) {
			for(j = 0; j <= i; j++) {
				subsum = prefixSum[i] - prefixSum[j] + A[j];
				if(subsum > max&&subsum<=m) {
					max = subsum;
					beg = j;
					end = i;
				}
			}
		}	
		printf("%d\n",max);*/
	return 0;
}
