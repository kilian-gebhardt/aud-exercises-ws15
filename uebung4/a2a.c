#include <stdio.h>

int main(){
	char name[99];

	printf("Wie heißt du?\n");
	scanf("%s", name);
	printf("\nMoin %s!\n", name);

	return 0;
}