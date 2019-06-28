#include <stdio.h>
#define ARRLEN (10)
int main (void)
{
int n[ARRLEN ]; /* n is an array of 10 integers */
	size_t i, j; /* Use size_t to address memory, that is to index arrays, as its guaranteed to
	be wide enough to address all of the possible available memory.
	Using signed integers to do so should be considered a special use case,
	and should be restricted to the uncommon case of being in the need of
	negative indexes. */

/* Initialize elements of array n. */
for ( i = 0; i < ARRLEN ; i++ )
	{
	n[ i ] = i + 100; /* Set element at location i to i + 100. */
	}
/* Output each array element's value. */
for (j = 0; j < ARRLEN ; j++ )
	{
	printf("Element[%zu] = %d\n", j, n[j] );
	}
return 0;
}
