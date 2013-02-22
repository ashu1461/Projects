#include<stdio.h>
#include<deque>
using namespace std;
// this is a nice programm to solve the longest increasing subsequence the easy way !
// just remember it !
int main()
{
	int n,m,i,ans=0,sum=0;
	scanf("%d %d",&n,&m);
	std::deque<int> d;
	int no;
	for(i=0;i<n;i++){
		scanf("%d",&no);
d.push_back(no);
		ans=ans+no;
		while(ans>m)
		{
			ans=ans-d[0];
d.pop_front();
		}
		sum=std::max(sum,ans);
	}
	printf("%d\n",sum);
	return 0;
}
