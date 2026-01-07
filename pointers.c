#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


void poner_bytes_0(void *b, int c, int n);

void *mi_calloc(size_t nmemb, size_t size);

void *mi_calloc(size_t nmemb, size_t size) {

	void *pointer = malloc(nmemb * size);

	if (!pointer) return NULL;

	poner_bytes_0(pointer, 0, size * nmemb);

	return pointer;

}

//nos mandan un puntero y en X bytes a partir de esa dirección ponemos el caracter c
void poner_bytes_0(void *b, int c, int n) {

	unsigned char *p = (unsigned char *)b;

	for (int i = 0; i < n; i++) {
		p[i] = (unsigned char) c;
	}

}

void pruebas() {
	int a = 1; 

	int *b = &a;

	printf("%p\n", &a);

	int myNumbers[4] = {25, 50, 75, 100};
	int i;

	for (i = 0; i < 4; i++) {
	  printf("%p\n", &myNumbers[i]);
	}

	printf("%zu\n", sizeof(myNumbers) / sizeof(myNumbers[0]));
}

int main(void) {

	int a = 1;

	int myNumbers[3] = {1, 2, 3};

	int *b = &a;

	int *array = mi_calloc(3, sizeof(int));

	for (int i = 0; i < 3; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	poner_bytes_0(myNumbers, 0, sizeof(myNumbers));

    for(int i = 0; i < 3; i++) {
    	printf("direccion = %p, valor = %d\n", &myNumbers[i], myNumbers[i]);
    }

}