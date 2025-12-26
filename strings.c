#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct {
	int value;
	struct Node *next;
} Node;

typedef struct {
	int num_elems;
	Node *first;
	Node *last;
} LinkedList;

void addNode(LinkedList *list, int value) {

	list->last = malloc(sizeof(Node));
	list->last->next = NULL;
	list->last->value = value;

	if (list->num_elems == 0) {
		list->first = list->last; 
	}

}

LinkedList *create_list(void) {

	LinkedList *list = malloc(sizeof(Node));
	list->first = NULL;
	list->last = NULL;
	list->num_elems = 0;
	return list;

}

void leer_escribir() {
	int fd = open("alumnos.txt", O_RDONLY);

	if ( fd < 0 ) exit(1);

	char buf[128];

	ssize_t n = read(fd, buf, sizeof(buf));

	write(1, buf, n);

	close(fd);
}

//split de python en c
char **split(const char *string, char sep, int *count) {

	int i = 0, //indice del string
	z = 0, //indice de array de palabras
	j = 0, //indice de palabras
	l = 0, //indice ultimo separador o 0 
	size = 0; //tamaño de la palabra
	*count = 0;

	//contamos cuantos separadores hay
	while(string[i]) {
		if (string[i] == sep) (*count)++;
		i++;
	}

	*count += 1;
	char **res = malloc((*count) * sizeof(char*));
	if (!res) return NULL;

	i = 0;
	while(string[i] != '\0') {

		if (string[i] == sep ) {
		
			//asignate string size
			size = j + 1;
			//allocate memory
			res[z] = malloc(sizeof(char)*size);
			//asign strings
			for (int h = 0; h < size - 1; h++) res[z][h] = string[l+h];
			//assing end of string
			res[z][j] = '\0';
			//reiniciar el contador de palabra
			j = 0;
			//aumentar el contador de array de palabras
			z++;
			//asignar i como ultimo indice de separador 
			l = i + 1;
		} else j++;
		i++;

	}

	size = j + 1;
	res[z] = malloc(sizeof(char)*size);
	for (int h = 0; h < size - 1; h++) res[z][h] = string[l+h];
	res[z][j] = '\0';

	return res;

}

char *join(char **array, int count, char sep) {

	//pasamos por el array para calcular el tamaño de cada palabra
	int i = 0, j = 0, size = 0, k = 0;
	while(i < count) {
		while(array[i][j++] != '\0') size++;
		i++; j=0;
	}

	size += (count - 1) + 1; //size es size + los separadores + el caracter nulo

	char *result = malloc(sizeof(char)*size);

	i = 0; j = 0;
	while( i < count ) {

		while(array[i][j] != '\0') {
			result[k] = array[i][j];
			j++;
			k++;
		}

		if (i < count - 1) result[k] = sep;
		i++;
		j = 0;
		k++;
	}

	result[k] = '\0';

	return result;

}


void liberar_memoria(char **array, int size) {

	for (int i = 0; i < size; i++) {
		free(array[i]);
	}

	free(array);

}

//asks a string and executes a function until you type quit
void ask_execute() {

	int salir = 0;
	char s[256];
	int count = 0;
	char **string_array;

	while(1) {
		
		printf("Escribe algo\n");
		fgets(s, 256, stdin);
		if (strcmp(s, "quit\n") == 0) break;

		string_array = split(s, ' ', &count);
		printf("%d\n", count);
		for (int i = 0; i < count; i++) printf("%s\n", string_array[i]);

		liberar_memoria(string_array, count);
	}

}

#define SIZE 4

//leer y escribir solo con llamadas al sistema
int main(int argc, char *argv[]) {

	//ask_execute();
	printf("");
	printf("\0");

	char *array[SIZE] = {"hola", "que", "tal", "adios"};
	char *res = join(array, SIZE, '-');
	printf("%s", res);

	free(res);

	return 0;

}