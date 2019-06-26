/* my_pow.c -- Print out powers of k: 1, k, k^2, k^3, .. up to k^N */

#include <stdio.h>
#include <math.h>
int main(void)
{
    int N = 16;
    int k = 2;

    int n;                      /* The current exponent */
    int val = 1;                /* The current power of k  */

    printf("\t  n  \t    2^n\n");
    printf("\t================\n");

    /* Add here a for loop that at each iteration prints out
       the current value of the power and updates val */
for (N=1;N<17;N++){
	val=pow(k,N);
	printf("\t	%d \t	%d\n",N,val);	
}

    return 0;
}
