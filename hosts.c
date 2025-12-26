#include "stdio.h"
#include "regex.h"



int main(int argc, char *argv[]) {

	FILE *f = fopen("C:\\Windows\\System32\\drivers\\etc\\hosts", "r");

	if (!f) {
		perror("Error escribiendo el archivo");
		return 1;
	}

	char linea[256];

	while(fgets(linea, sizeof(linea), f)) {
		printf("%s", linea);
	}

	return 0;

}