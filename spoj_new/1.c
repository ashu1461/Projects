#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,x,w[5],ww[5],r[5],cnt[5][100005],sum[5][100005];
long long b,y[100005],a[5][100005],temp,o1,o2;

void pro()
{
	//printf("b %lld \n",b);
	while ((r[1]<ww[1])&&(a[1][r[1]]<b))
	{
		r[1]++;
	}
	while ((r[2]<ww[2])&&(a[2][r[2]]<=b))
	{
		r[2]++;
	}
	while ((r[3]<ww[3])&&(a[3][r[3]]<b))
	{
		r[3]++;
	}
	while ((r[4]<ww[4])&&(a[4][r[4]]<b))
	{
		r[4]++;
	}
	temp=0;
	if (r[1]>0)
	{
		temp+=sum[1][r[1]-1];
	}
	//printf("%lld\n",temp);
	if (r[2]>0)
	{
		//printf("%d %d %lld\n",r[2],sum[2][r[2]-1],temp);
		temp+=w[2]-sum[2][r[2]-1];
	}
	else
	{
		temp+=w[2];
	}
	//printf("%lld\n",temp);
	if ((r[3]<ww[3])&&(a[3][r[3]]==b))
	{
		temp+=cnt[3][r[3]];
	}
	//printf("%lld\n",temp);
	if ((r[4]<ww[4])&&(a[4][r[4]]==b))
	{
		temp+=w[4]-cnt[4][r[4]];
	}
	else
	{
		temp+=w[4];
	}
	//printf("%lld\n",temp);
	if (temp>o1)
	{
		o1=temp;
		o2=b;
	}
}	

int main()
{
	scanf("%d",&n);
	memset(w,0,sizeof(w));
	for (int i=0; i<n; i++)
	{
		scanf("%d%lld",&x,&y[i]);
		a[x][w[x]++]=y[i];
	}
	for (int i=1; i<=4; i++)
	{
		if (w[i])
		{
			sort(a[i],a[i]+w[i]);
			ww[i]=1;
			cnt[i][0]=1;
			for (int j=1; j<w[i]; j++)
			{
				if (a[i][j]!=a[i][j-1])
				{
					a[i][ww[i]++]=a[i][j];
					cnt[i][ww[i]-1]=1;
				}
				else
				{
					cnt[i][ww[i]-1]++;
				}
			}
			sum[i][0]=cnt[i][0];
			for (int j=1; j<ww[i]; j++)
			{
				sum[i][j]+=sum[i][j-1]+cnt[i][j];
			}
		}
		else
		{
			ww[i]=0;
		}
	}
	sort(y,y+n);
	memset(r,0,sizeof(r));
	o1=0;
	b=0;
	pro();
	for (int i=0; i<n; i++)
	{
		if (y[i]-1>b)
		{
			b=y[i]-1;
			pro();
		}
		if (y[i]>b)
		{
			b=y[i];
			pro();
		}
		if (y[i]+1>b)
		{
			b=y[i]+1;
			pro();
		}
	}
	printf("%lld %lld\n",o1,o2);
	return 0;
}

