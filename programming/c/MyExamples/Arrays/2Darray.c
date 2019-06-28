#include <stdio.h>
void main(){
int i,j;
float matrix[5][5], *ptr[][5];
ptr=matrix;
for (i=0; i<5; i++){
    for (j=0; j<5; j++){
	matrix[i][j] = i*j;
    }
}

//print the 2th row
for (i=0; i<5; i++){
    printf("%f\n",matrix[1][i]);
}
}
