#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define DX 0.01
#define DY 0.01

// Field structure definition
typedef struct {
    // TODO: write a structure definition similar to Ex.4d, but now the
    // data array should be for a dynamically allocated 2D array
    int nx;
    int ny;
    double dx;
    double dy;
    double dx2;
    double dy2;
    double **data;
    
} field;

// Function prototypes
void init_field(field *f, int nx, int ny);

void laplacian(field *f);

void print_field(field *f);

#endif
