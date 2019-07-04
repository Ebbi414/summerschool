#ifndef whatever
#define whatever

#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 258
#define NY 258

#define DX 0.01
#define DY 0.01

int array_values(double a[NX][NY]);

double* laplacian(double array[NX][NY]);
#endif
