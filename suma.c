#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void freebuffer() {
	int c;
	while ( ( c = getchar()) != '\n' && c != EOF );
}

void printParams(int argc, char **argv) {
	for (int i = 0; i < argc; i++) {
		printf("%d-%s - version atoi = %d\n", 
			strlen(argv[i]), 
			argv[i], 
			atoi(argv[i]));
	}
}

bool isInteger() {
	return false;
}

void reverse(int *arr, int n) {

}

void printArrayPositions() {
	
}

int main(int argc, char **argv) {

	int length = 5;

	int array[length];

	printf("%zu", sizeof(array[0]));

	return 0;

	for (int i = 0; i < length; i++) {
		printf("%d\n", &array[i]);
	}

	printf("-------\n");

	double array2[length];

	for (int i = 0; i < length; i++) {
		printf("%d\n", &array2[i]);
	}

	for (int i = 0; i < length; i++) {
		printf("Introduce el siguiente numero\n");

		while (scanf("%d", &array[i]) != 1) {
			freebuffer();
			printf("Introduce el numero de nuevo:");
		}
		
	}

	printf("Que hay en el array?\n");

	for (int i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}

	int suma = 0;
	int mayor = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] > mayor) mayor = array[i];
		suma += array[i];
	}

	printf("Suma? \n%d\n", suma);

	printf("Mayor? \n%d\n", mayor);

	return 0;
}