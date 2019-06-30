#include "funH.h\
"

int  main(void){

    double *laplacian(double array[NX][NY])
    {

    int i, j; //error_code;
    static double laplacian[NX][NY]; //make the variable global

    // Zero out the outer boundary of laplacian
    for (i = 0; i < NX; i++) {
        laplacian[i][0] = laplacian[i][NY - 1] = 0.0;
    }
    for (j = 0; j < NY; j++) {
        laplacian[0][j] = laplacian[NX - 1][j] = 0.0;
    }


    // Evaluate the Laplacian
    // *INDENT-OFF*

    for (i = 1; i < NX - 2; i++) {
        for (j = 1; j < NY - 2; j++) {
            laplacian[i][j] =
                (array[i-1][ j ] - 2.0 * array[i][j] + array[i+1][ j ]) / (DX * DX) +
                (array[ i ][j-1] - 2.0 * array[i][j] + array[ i ][j+1]) / (DY * DY);
        }
    }
    // *INDENT-ON*

    // Call the png writer routine
    /* error_code = save_png((double *) laplacian, NX, NY, "datastructures_functions_heat-a_b.png", 'c');

    if (error_code == 0) {
        printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
    } else {
        printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
    }*/

    return &laplacian[0][0];
}

