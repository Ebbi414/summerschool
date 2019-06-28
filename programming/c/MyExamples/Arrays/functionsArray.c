#include "funH.h"

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
