/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'runlenngthmathematics'
  date->Sat Jun  2 10:30:58 IST 2012*/
#include<stdio.h>
long long int decode(long long int a)
{
	if(a==0)
		return 10;
	int prev=a%10;
	int ans=0;
	int counter=0;
	while(a>0)
	{
		if(a%10==prev)
		{
			counter++;
			a=a/10;

		}
		else
		{
			int hell=0;
			while(counter>9)
			{
				hell++;
				counter=counter-9;
			}
			ans=ans*100+counter*10+prev;
			while(hell--)
			{
				ans=ans*100+90+prev;
			}
			prev=a%10;
			counter=0;
		}

	}
	int hell=0;
	while(counter>9)
	{
		hell++;
		counter=counter-9;
	}
	ans=ans*100+counter*10+prev;
	while(hell--)
	{
	ans=ans*100+90+prev;
	}
	long long int ans1=0;
	while(ans>0)
	{
		ans1=ans1*100+ans%100;
		ans=ans/100;
	}
	return ans1;
}
long long int encode(long long int a)
{
	long long int ans=0;
	int i,j;
	while(a>0)
	{	
		i=a%10;
		a=a/10;
		j=a%10;
		a=a/10;
		while(j--)
		{
			ans=ans*10+i;
		}
	}
	long long int ans1=0;
	while(ans>0)
	{
		ans1=ans1*10+ans%10;
		ans=ans/10;
	}
	return ans1;
}
int main()
{
	long long int a,b;
	char c;
	while(scanf("%lld %c %lld",&a,&c,&b)!=EOF)
	{
		long long int ans;
		switch(c){
			case('+'):
				{
					ans=encode(a)+encode(b);
					break;
				}
			case('-'):
				{
					ans=encode(a)-encode(b);
					break;
				}
			case('*'):
				{
					ans=encode(a)*encode(b);
					break;
				}
			case('/'):
				{
					ans=encode(a)/encode(b);
				}
		}
//				printf("Encode %lld %lld %lld\n",encode(a),encode(b),ans);
		printf("%lld %c %lld = %lld\n",a,c,b,decode(ans));
	}
	return 0;
}

