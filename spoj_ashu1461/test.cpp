#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char s[10000][10000];
	int i;
	for(i=0;i<5;i++){
		scanf("%s",s[i]);
	}
	std::sort(s,5);
	for(i=0;i<s;i++){
		printf("%s\n",s[i]);
	}

}
