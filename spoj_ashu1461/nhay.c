#include<stdio.h>
#include<string.h>
int main()
{
	int n=1;
	char a[100000],b[100000];
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",a);
		scanf("%s",b);
		int T[100000];
		int sta=strlen(a),stb=strlen(b);
		T[0]=-1;
		T[1]=0;
		int i=2,sub=0;
		while(i<sta)
		{
			if(a[i-1]==a[sub])
			{
				sub++;
				T[i]=sub;
				i++;
			}
			else if(sub>0)
				sub=T[sub];
			else
			{
				T[i]=0;
				i++;
			}
		}
		i=0;
		int m=0;
		int flag=0;
		while(m<stb)
		{
			if(a[i]==b[m+i])
			{
				if(i==sta-1)
				{
					printf("%d\n",m);
					m=m+i-T[i];
					i=T[i];
					flag=1;
				}
				i=i+1;
			}
			else
			{
				m=m+i-T[i];
				if(T[i]>-1)
					i=T[i];
				else
					i=0;
			}
		}
		printf("\n");
	}
	return 0;
}
