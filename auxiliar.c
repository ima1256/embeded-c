#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>
#include "nombres.h"
#include <windows.h>

#define SQUARE(x) ((x) * (x))

int suma(int a, int b) {
    return a + b;
}

char *rand_string(int n) {

	char *res; 

	int i = 0;
	while( i < n) {
		*res = 
		i++;
	}

}

int randLetter() {
	int offsets[2] = {65, 97};
	int offset = offsets[rand() % 2];
	return offset + (rand() % 26);
}

void print_things();

void print_things(char *string) {
	for (int i = 5; i < 10; i++) {
		printf("%s\n", string);
	}
}

int power(int base, int exponente) {

	int res = 1; 

	for (int i = 0; i < exponente; i++) {
		res *= base;
	} 

	return res;

}

void print_sizes() {
	printf("%zu\n", sizeof(char));
	printf("%zu\n", sizeof(short));
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(long));
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(float));
	printf("%zu\n", sizeof(double));
	printf("%zu\n", sizeof(long double));
}

void ejemplo() {
	int a = 5;
    int b = 2;

    printf("%d\n", a / b);
    printf("%f\n", a / b);
    printf("%f\n", (double)a / b);
}


void print_bits(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1); // desplazamos y aplicamos AND con 1
    }
    printf("\n");
}

typedef enum {
  SCHOOL,
  COLLEGE,
  MASTERS
} Level;

typedef struct {
	int id;
	char *nombre;
	float nota;
} Alumno;

typedef struct {
	int id;
	char *nombre;
	Level level;
} Teacher;

typedef struct {
	struct Alumno* alumnos;
	int size;
} Alumnos;

void imprimirAlumno(Alumno *alumno) {
	printf("Id = %d, nombre = %s, nota = %.2f\n", 
		alumno->id, alumno->nombre, alumno->nota);
}

int main() {

	unsigned int h1 = 300;
	unsigned int h2 = 200;

	printf("\n");

	print_bits(h1);
	print_bits(h2);

	print_bits(~(h1 | h2));

	printf("\n");

	return 0;

	SetConsoleOutputCP(CP_UTF8);

	ejemplo();

	float myNum = 5.75;
	printf("%.2f\n", myNum);

	double d1 = 0.1 + 0.2;

	printf("%.17f\n", d1);

	if (fabs(d1 - 0.3) < 1e-9) {
    	printf("Son prácticamente iguales\n");
	}

	print_sizes();

	long long xx = 3 << 10;

	print_bits(xx);

	int value = rand();

	int i = 0;

	int square_size = 5;

	int x = 50000;

	int y = x * x;

    unsigned long long z = 1 << 31;
    //z = z << 31;

    printf("z = %u\n", z);

	while(i < square_size * square_size) {

		printf("%d ", value);
		i++;

		if (i % square_size == 0) {
			printf("\n");
		}

	}

	printf("%d", SQUARE(6));

	return 0;

}