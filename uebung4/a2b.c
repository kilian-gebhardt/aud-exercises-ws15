#include <stdio.h>

int main(){
	unsigned n, i, j, x;

	printf("Wie ist n?\n");
	scanf("%u", &n);

	for(i = 1; i <= n; i = i + 1){
		for (j = 1; j <= n; j = j + 1){
			x = i * j;
			printf("%u\t",x);
		}
		printf("\n");
	}
		
	return 0;
}