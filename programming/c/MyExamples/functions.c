#include <stdio.h>
void Addone(int *a, int *b)
{
	(*a) +=1;
	(*b) +=1;
}

void main()
{
int a,b;
int *p,*t;
a = 10; b = 12;
p = &a; t = &b;
printf("Initially: a is %d and b is %d\n", a, b);
Addone(p,t);
printf("Finally: a is %d and b is %d\n", a, b);
}
