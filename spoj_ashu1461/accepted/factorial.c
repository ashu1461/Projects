#include<stdio.h>
#include<gmp.h>
int main()
{
	mpz_t a,b,r;
	mpz_init(a);
	mpz_init(b);
	mpz_init(r);
	mpz_set_str(a,"100",10);
	mpz_set_str(b,"100",10);
	mpz_mul(r,a,b);
	mpz_out_str(stdout,10,2);
	putchar('\n');
	return 0;

}
