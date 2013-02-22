/* "qsort" is declared in stdlib.h. */
#include <stdlib.h>
#include <stdio.h>
/* string.h declares "strcmp". */
#include <string.h>

/* "array" is an unsorted shopping list. */

char * array[] = {
/*	"eggs",
	"bacon",
	"cheese",
	"mushrooms",
	"spinach",
	"potatoes",
	"spaghetti",*/
};

/* n_array is the number of elements in the array. */

#define n_array sizeof(array)/sizeof(char *);

/* Compare the strings. */

static int compare (const void * a, const void * b)
{
	/* The pointers point to offsets into "array", so we need to
	   dereference them to get at the strings. */

	return strcmp (*(const char **) a, *(const char **) b);
}

int main ()
{
	char s[200000];
	scanf("%s",s);
	int i;
//	for(i=0;i<strlen(s);i++)
//	printf("%s\n",s+i);
//	array[i]=(char*)malloc((strlen(s+i)+1)*sizeof(char));
//	strcpy(array[i],s+i);
//	}
//	qsort (array, n_array, sizeof (char *), compare);
	for (i = 0; i < n_array; i++) {
		printf ("%d: %s.\n", i, array[i]);
	}
	return 0;
}
