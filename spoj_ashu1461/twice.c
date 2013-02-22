/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'TWICE'
  date->Tue Jun  5 05:33:40 IST 2012*/
/* "qsort" is declared in stdlib.h. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int compare (const void * a, const void * b)
{

	return strcmp (*(const char **) a, *(const char **) b);
}
int main ()
{
	int no;
	scanf("%d",&no);
	int i;
	char s[no];
	scanf("%s",s);
	char *array_string[no];
	for(i=0;i<no;i++){
		array_string [i]=(char*)malloc((no-i+1)*sizeof(char));
		strcpy(array_string[i],s+i);
	}
	qsort (array_string,no, sizeof (const char *), compare);
	int j;
	int max=-1;
	int p;
	for(i=0;i<no-1;i++){
		if(strlen(array_string[i])<strlen(array_string[i+1]))
			p=strlen(array_string[i]);
		else
			p=strlen(array_string[i+1]);
		for(j=0;j<p;j++)
		if(array_string[i][j]!=array_string[i+1][j])
			break;
		if(j>max)
			max=j;
	}
	printf("%d\n",max);
	return 0;
}
