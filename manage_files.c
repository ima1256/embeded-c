#include "stdio.h"



int main(int argc, char **argv) {

	FILE *f = fopen("datos.txt", "w");

	if (f == NULL) {
	    perror("Error al abrir archivo");
	    return 1;
	}

	for (int i = 0; i < argc; i++) {
		fprintf(f, "%i - %s\n", i + 1, argv[i]);
	}

	fclose(f);

}