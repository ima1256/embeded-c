#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int value;
	Node *next;
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

char **split(char *string, char sep, int *count) {

	int i = 0, j = 0, tokens = 0;
	char *start = string;
	*count = 0;

	//contamos cuantos separadores hay
	while(*string) {
		if (*string == sep) (*count)++;
		string++;	
	}

	tokens = (*count) + 1;
	string = start;
	char **res = malloc((tokens) * sizeof(char*));

	if (!res) return NULL;

	i = 0;
	int word_size = 0;
	char *word_start = *string
	while(*string) {

		if (*string == sep ) {
			res[i][j] = '\0';
			i++;
			j = 0;
			word_size = 0;
		} else {
			res[i][j] = *string; 
			j++;
			word_size++;
		}	
		string++;

	}

	string = start;
	res[i][j] = '\0';

	return res;

}

void liberar_memoria(char **array, int size) {

	for (int i = 0; i < size; i++) {
		free(array[i]);
	}

	free(array);

}

//leer y escribir solo con llamadas al sistema
int main(int argc, char *argv[]) {

	int count = 0;

	char **string_array = split("hola que tal", ' ', &count);

	printf("%d", count);

	printf("%s", string_array[0]);

	liberar_memoria(string_array, count);

	return 0;

}