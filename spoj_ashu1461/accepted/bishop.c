/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'BISHOP'
  date->Tue Jun  5 14:56:21 IST 2012*/
#include<stdio.h>
#include<string.h>
int main()
{
	char s[10000];
	int n;
	while(scanf("%s",s)!=EOF){
	int sta=strlen(s);
	if(sta==1&&(s[0]=='1'||s[0]=='0')){
		printf("%s\n",s);
	}
	else{
	int i;
	int no;
	int carry=0;
	for(i=sta-1;i>=0;i--){
		no=(int)s[i]-48;
		s[i]=(no*2+carry)%10+48;
		carry=(no*2+carry)/10;
	}
	if(carry==1){
		for(i=sta;i>0;i--){
			s[i]=s[i-1];
		}
		s[0]='1';
	}
//	printf("%s\n",s);
	sta=strlen(s);
	carry=0;
//	printf("length is now %d\n",sta);
//	printf("here %c\n",s[sta-1]);
	// now just subtract 2;
		if(s[sta-1]=='1'){
			s[sta-1]='9';
			carry=-1;
		}
		else if(s[sta-1]=='0'){
//			printf("here");
			s[sta-1]='8';
			carry=-1;
		}
		else {
			s[sta-1]=s[sta-1]-2;
		}
//		printf("here we do %s\n",s);
		if(carry==-1){
			i=sta-2;
			while(s[i]=='0'){
				s[i]='9';
				i--;
			}
			s[i]=s[i]-1;
		}
		if(s[0]=='0'){
			printf("%s\n",s+1);
		}
		else{
	printf("%s\n",s);
		}
	}
	}
	return 0;
}

