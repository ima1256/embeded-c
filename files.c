#include <stdio.h>
#include <stdlib.h>

void invertir(int *v, int n) {

	int *a = v;
	for (int i = 0; i < n - 1; i++) v++;

	int *b = v;

	v = a;

	int i = 0;
	while ( i < n / 2) {
		int temp = *a;
		*a = *b;
		*b = temp;
		i++;
		a++;
		b--;
	}

}

void duplicar(int *v, int n) {

	for(int i = 0; i < n; i++) {
		*v = *v * 2;
		v++;
	}

}

int main() {

	//crear archivo metada alumnos

	int v[5] = {1, 2, 3, 4, 5};

	int *h = calloc(5, sizeof(int));

	for( int i = 0; i < 5; i++) {
		printf("%d\n", *h);
		h++;
	}

	//duplicar(v, 5);

	invertir(v, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", v[i]);
	}

	FILE *f = fopen("numeros.txt", "w");

	for (int i = 0; i < 10; i++) {
		fprintf(f, "%d\n", i);
	}

	fclose(f);

	f = fopen("numeros.txt", "r");

	char mystring[100];

	char *g = fgets(mystring, 100, f);

	printf("Este es el char que devuelve fgets %d", g);

	printf("%s %d", mystring, g);

	fclose(f);

	return 0;
}