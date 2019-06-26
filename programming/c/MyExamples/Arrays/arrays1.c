#include <stdio.h>
int main(){
float array[10]={1,2,3};
//	int array[5] = {[2] = 5, [1] = 2, [4] = 9}; /* array is {0, 2, 5, 0, 9}*/ 
//	int array[] = {1, 2, 3}; /* an array of 3 int's */
//	int array[] = {[3] = 8, [0] = 9}; /* size is 4 */
//	size_t m = calc_length(); /* calculate array length at runtime */
//	int vla[m]; /* create array with calculated length */
int i;
for (i=0;i<11;i++){
	printf("%.2f\n",array[i]);
}
return 0; 
}
