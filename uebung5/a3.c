#include <stdio.h>

void swap(int * x, int * y){
	int z;

	if (*x % 2 == 1)
		*x = *x + 1;
	z = *y;
	*y = *x;
	*x = z;
}

int main(){
	int a, b;

	a = 5;
	b = 7;

	swap(&a, &b);

	/* a = 7, b = 6*/
	printf("a = %d and b = %d\n", a, b);

	return 0;
}