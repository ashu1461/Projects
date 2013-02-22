/*Ashutosh Singla  <ashu1461@gmail.com>
  programm-> 'TWICE'
  date->Tue Jun  5 05:33:40 IST 2012*/
/* "qsort" is declared in stdlib.h. */
#include <stdlib.h>
#include <stdio.h>
/* string.h declares "strcmp". */
#include <string.h>

/* "array" is an unsorted shopping list. */

const char * array[] = {
/*	"eggs",
	"bacon",
	"cheese",
	"mushrooms",
	"spinach",
	"potatoes",
	"spaghetti",*/
};

/* n_array is the number of elements in the array. */

#define n_array sizeof(array)/sizeof(const char *)

/* Compare the strings. */

static int compare (const void * a, const void * b)
{
	/* The pointers point to offsets into "array", so we need to
	   dereference them to get at the strings. */

	return strcmp (*(const char **) a, *(const char **) b);
}
int main ()
{
	int no;
	scanf("%d",&no);
	int i;
	char s[200000];
	scanf("%s",s);
	char *array_string[strlen(s)];
	for(i=0;i<strlen(s);i++){
		array_string [i]=(char*)malloc((strlen(s+i)+1)*sizeof(char));
		strcpy(array_string[i],s+i);
	}
	int large=sizeof(array_string)/sizeof(char*);
	qsort (array_string,large, sizeof (const char *), compare);
//	for (i = 0; i <large; i++) {
//		printf ("%s\n",array_string[i]);
//	}
	int j;
	int max=-1;
	for(i=0;i<large-1;i++){
		j=0;
		// compare between i and i+1;
		while(j<strlen(array_string[i]) && j<strlen(array_string[i+1])){
		if(array_string[i][j]==array_string[i+1][j])
		j++;
		else
			break;
			}
		if(j>max)
			max=j;
//		printf("%d %d\n",i,j);
	}
	printf("%d\n",max);
	return 0;
}

