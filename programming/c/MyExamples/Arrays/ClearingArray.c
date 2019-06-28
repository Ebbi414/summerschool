#include <stdlib.h> /* for EXIT_SUCCESS */
#define ARRLEN (10)
int main(void)
{
int array[ARRLEN]; /* Allocated but not initialised, as not defined static or global. */
size_t i;
for(i = 0; i < ARRLEN; ++i)
{
array[i] = 0;
}
return EXIT_SUCCESS;
}
