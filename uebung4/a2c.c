# include <stdio.h>

# define LEN 1001

int main(){
	unsigned sieve[LEN], i, j;

	sieve[0] = 0;
	sieve[1] = 0;

	for(i = 2; i < LEN; i = i + 1){
		sieve[i] = 1;
	}

	for(i = 2; i < LEN; i = i + 1){
		if (sieve[i] == 1){
			for (j = 2; i * j < LEN; j = j + 1){
				sieve[ i * j ] = 0;
			}
		}
	}

	for(i = 0; i < LEN; i = i + 1){
		if (sieve[i] == 1){
			printf("%u, ", i);
		}
	}

	return 0;
}