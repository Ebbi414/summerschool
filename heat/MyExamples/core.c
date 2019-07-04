/* Main solver routines for heat equation solver */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "heat.h"

/* Update the temperature values using five-point stencil */
void evolve(field *curr, field *prev, double a, double dt)
{
    int i, j;
    double dx2, dy2;

    /* Determine the temperature field at next time step
     * As we have fixed boundary conditions, the outermost gridpoints
     * are not updated. */
    dx2 = prev->dx * prev->dx; 
	/*=(*prev).dx f is a pointer to a struct so to access a member (*f).xn = f->xn */
    dy2 = prev->dy * prev->dy;

    /* TODO: Add update loops for computing the new field values
             of 'curr' using field 'prev' */

    // Initialize first the zeros
    for (i = 1; i < curr->nx; i++) {
        for (j = 1; j < curr->ny; j++) {
            curr->data[i][j] =
                prev->data[i][j] + a* dt * ((prev->data[i+1][j] -
		2.0 * prev->data[i][j] + prev->data[i-1][j])/dx2 +
		(prev->data[i][j+1] - 2.0 * prev->data[i][j] +
		prev->data[i][j-1]) / dy2);
	}
    }
}


