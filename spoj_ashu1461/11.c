#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int flag=0,flag11=0;
		char s[100003];
		scanf("%s",s);
		int i,sta=strlen(s),mid;
		// firstly to check whether the string is 9... or not
		for(i=0;i<sta;i++)
		{
			if(s[i]!='9')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("1");
			for(i=1;i<sta;i++)
				printf("0");
			printf("1");
			printf("\n");
			//	return ;
			flag11=1;
		}
		if(flag!=0)
		{
			char p[100];
			strcpy(p,s);
			// the number is not of the form .. !! 
			// first obtain the mirror image
			int flag1=0;
			for(i=0;i<sta/2;i++)
				s[sta-i-1]=s[i];
			flag1=strcmp(p,s);
			// if flag is 0 or 1 we need to take action !! 
			if(sta%2==0)
				mid=sta/2-1;
			else
				mid=sta/2;
			if(flag1!=-1)
			{
				int j=0;
				while(s[mid-j]=='9')
				{
					s[mid-j]='0';
					s[sta-mid+j-1]='0';
					j++;
				}
				s[mid-j]++;
				s[sta-1-mid+j]=s[mid-j];
			}
			printf("%s\n",s);
		}
		test--;
	}
	return 0;
}
