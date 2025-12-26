#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "limits.h"
#include "time.h"
#include "nombres.h"
#include "math.h"

#define MAX_SIZE 100

unsigned int generateID() {
    static unsigned int counter = 0; // conserva su valor entre llamadas
    return ++counter;
}

typedef struct {
	int id;
	char nombre[50];
	float nota;
} Alumno;

typedef struct {
	int size;
	Alumno *elems[MAX_SIZE];
} Alumnos;

int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

float randFloat(float min, float max) {
	return min + ((float) rand() / (float) RAND_MAX) * ( max - min);
}

float randNota() {
	float x = randFloat(0, 10);
	return roundf(x * 100) / 100;
}

const char *randNombre() {
	int index = randInt(0, total_nombres - 1);
	return nombres[index];
}

void rellenarAlumno(Alumno *al) {
	al->id = generateID();
	strcpy(al->nombre, randNombre());
	al->nota = randNota();
}

void imprimirAlumno(Alumno *alumno) {
	printf("Id = %d, nombre = %s, nota = %.2f\n", 
		alumno->id, alumno->nombre, alumno->nota);
}

void initialize_seed() {
	srand((unsigned)time(NULL));
}

void initializeAlumnos(Alumnos *als) {

	for (int i = 0; i < 10; i++) {
		Alumno *al = malloc(sizeof(Alumno));
		rellenarAlumno(al);
		als->elems[i] = al;
		imprimirAlumno(als->elems[i]);
	}
}

void getAlumno(char *linea, Alumno* alumno) {



}

int meterTexto() {

	FILE *f = fopen("alumnos.txt", "w");

	if (!f) {
		perror("Error escribiendo el archivo");
		return 1;
	}

	printf("Mete el texto que quieras\n");

	char s[100]; 

	while(1) {

		scanf("%99s", s);

		if (strcmp(s, "salir") == 0) break;

		fprintf(f, "%s\n", s);

	}

	fclose(f);

	return 0;

}

int cargarAlumnos(Alumnos *alumnos) {

	FILE *f = fopen("alumnos.txt", "r");

	if (!f) {
		perror("Error escribiendo el archivo");
		return 1;
	}

	int i = 0;
	char linea[256];
	while(fgets(linea, sizeof(linea), f)) {
		alumnos->elems[i] = malloc(sizeof(Alumno));
		Alumno* alumno = alumnos->elems[i];
		if (sscanf(linea, "%d %49s %f", &(alumno->id), alumno->nombre, &(alumno->nota)) == 3) {
	    	printf("OK -> %d %s %.2f\n", alumno->id, alumno->nombre, alumno->nota);
		}
		i++;
	}

}

int buscarAlumno(int id, Alumno *alumno) {

}

int anadirAlumno(Alumno *alumno) {

	FILE *f = fopen("alumnos.txt", "a+");

	fclose(f);

}

typedef struct {
	char key[50];
	char value[50];
} Metadata;

typedef struct {
	char key[50];
	char value[50];
	//DictElem *next;
} DictElem;

typedef struct {
	int size;
} Dict;

DictElem getMetadata(char key[50]) {
	
	FILE *f = fopen("metadata.txt", "r");

	char linea[256];
	while(fgets(linea, sizeof(linea), f)) {

	}

	fclose(f);

}

int main() {

	initialize_seed();

	Alumnos *als = malloc(sizeof(Alumnos));

	//initializeAlumnos(als);

	int res = cargarAlumnos(als);

	if (res) return 1;

	//Buscamos un alumno por id



	return 0;

}

