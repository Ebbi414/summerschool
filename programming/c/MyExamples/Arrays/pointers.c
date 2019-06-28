#include <stdio.h>
void main(){
int i,j,t,k;
float matrix[5][5], *p;

for (i=0; i<5; i++){
    for (j=0; j<3; j++){
        matrix[i][j] =i*j;
    }
}

//print the 2th row
for (t=0; t<5; t++){
    printf("%f\n",matrix[1][t]);
}

//print with pointers
p = &matrix[0][0];
for (k=0; k<15; k++){
    printf("\n %f\n",*(p+k));
}
}


