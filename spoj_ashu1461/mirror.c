#include<stdio.h>
int main()
{
	printf("Ready\n");
	while(1)
	{
		char a,b;
	scanf("%c%c",&a,&b);
	if(a==' '&&b==' ')
		break;
	else if((a=='b'&&b=='d')||(a=='d'&&a=='b')||(a=='p'&&b=='q')||(a=='q'&&b=='p'))
		printf("Mirrored pair\n");
	else
		printf("Ordinary pair\n");
	}
}
