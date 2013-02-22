/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'easyprob'
  date->Fri Dec 21 00:52:31 IST 2012*/
#include<stdio.h>
#include<string.h>
int i;
char s[102];
int function(){
	int ans=0;
	int c=0,h=0,o=0;
	int k;
//	printf("%d %d\n",i,strlen(s));
	while(i<strlen(s))
	{
		if(i+1<strlen(s)){
			k=(int)s[i+1]-48;
		}
		else
			k=12;
		if(s[i]=='C'){

			if(1<k&&k<10){
				c=c+k-48;
				i++;
			}
			else
				c++;
		}
		else if(s[i]=='H')
		{
			if(1<k&&k<10){
				h=h+k;
				i++;
			}
			else
				h++;
		}
		else if(s[i]=='O')
		{
			if(1<k&&k<10){
				o=o+k;
				i++;
			}
			else
				o++;
		}
		else if(s[i]==')'){
			{
				if(1<k&&k<10){
					ans=(ans+(c*12+h+o*16))*k;
					i++;
				}
				else
					ans=ans+c*12+h+o*16;
			}
			return ans;
		}
		else if(s[i]=='('){
			i=i+1;
			ans=ans+function();
		}	
		i++;
	}
	ans=ans+c*12+h+o*16;
	return ans;

}
int main()
{
//	scanf("%[^,\n]",s);
	gets(s);
	i=0;
int ans=	function();
	printf("%d\n",ans);
	return 0;
}

