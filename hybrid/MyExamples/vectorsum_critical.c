#include <stdio.h>

#define NX 102400

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex, total;
    int i;

    /* Initialization of the vectors */
    
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i + 1;
    }

    sumex = (long) NX * (NX + 1) / ((long) 2);
    printf("Arithmetic sum formula (exact):                  %ld\n",
           sumex);

    sum = 0.0; total = 0;

    /* TODO: Parallelize computation */
#pragma omp parallel shared(total) private(i,sum)
{
sum = 0; 
       //initialize();
#pragma omp for
	for (i = 0; i < NX; i++) {
        	sum += vecA[i];
    	}

    #pragma omp critical(addup)
	total += sum;
    #pragma omp barrier //make sure that all threads add to total 
    #pragma omp master
    	printf("Sum: %ld partial in master %ld\n", total, sum);
}
    return 0;
}
