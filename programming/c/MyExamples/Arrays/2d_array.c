#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258


int array_values(double a[NX][NY]){
    // Initialize first the zeros
    int i,j;
    for (i=0; i<NX; i++){
        for (j=0; j<NY-1; j++){
        a[i][j]=0.0;
        }
    }

    // Initial conditions for left and right
    for (i=0; i<NX; i++){
        a[i][0] = 20.0;
        a[i][NY-1] = 70.0;
    }

    // and top and bottom boundaries
    for (j=0; j<NY; j++){
        a[0][j] = 85.0;
        a[NX-1][j] = 5.0;
    }
return 0;
}


int main(void)
{
    int i;

    // Add here the definition for array with name 'array' of size NX times NY (258x258)
    double array[NX][NY];
i = array_values(array);
return i;
}


