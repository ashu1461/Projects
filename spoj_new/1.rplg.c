/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'niceporblem'
date->Sat Dec 22 03:33:27 IST 2012*/
#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	scanf("%[^,\n]",s);
	int i;
	for(i=0;i<strlen(s);i++)
		printf("%s\n",s+i);
return 0;
}

