#include <stdio.h>
#include <stdlib.h>


int sumar(int a, int b) {
	return a + b; 
}

int restar(int a, int b) {
	return a - b; 
}

int inArray(int *v, int x, int n) {

	for (int i = 0; i < n; i++) {
		if (v[i] == x) {
			return 1;
			break;
		}
	}

	return 0;

}

int main() {

	int (*fs[2])(int, int) = {sumar, restar};
	int *numeros = calloc(2, sizeof(int));
	int res = 0;

	int opciones[3] = {1, 2, -1}; 

	int b = inArray(opciones, 1, 2);

	while(1) {
		
		for (int i = 0; i < 2; i++) {
			printf("Mete el numero %d:\n", i+1);
			scanf("%d", &numeros[i]);
		}

		int opcion = -2;
		while( !inArray(opciones, opcion, 3) ) {
			printf("Que operacion quieres hacer?\n");
			scanf("%d", &opcion);
		}

		if (opcion == -1) break;

		res = fs[opcion-1](numeros[0], numeros[1]);

		printf("El resultado de la operacion es %d\n", res);

	} 

	printf("Ha sido un placer, hasta pronto");

	return 0;

}