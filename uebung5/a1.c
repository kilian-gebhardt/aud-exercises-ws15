#include <stdio.h>

unsigned fib(unsigned n){
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	if (n > 1)
		return fib(n-1) + fib(n-2);
}

unsigned G(unsigned n){
	if (n == 0)
		return 0;
	else
		return n - G(G(n-1));
}

unsigned M(unsigned);

unsigned F(unsigned n){
	if (n == 0)
		return 1;
	return n - M(F(n-1));
}

unsigned M(unsigned n){
	if (n == 0)
		return 0;
	return n - F(M(n-1));
}


int main(){
	unsigned m;
	for (m = 0; m < 15; m = m + 1){
		printf("fib(%2u) = %4u\t", m, fib(m));
		printf("G(%2u) = %2u\t", m, G(m));
		printf("F(%2u) = %2u\t", m, F(m));
		printf("M(%2u) = %2u\n", m, M(m));
			
	}
	return 0;
}