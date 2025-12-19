#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *name;
	int age;
} Person

int main() {
  char name[10] = "John";
  name[1] = 'Z';
  name[4] = 'h';
  name[5] = '\0';

  int longitud = strlen(name);

  printf("Hello %s\n", name);

  printf("La longitud es %d\n", longitud);

  strcat(name, "Xfg");

  longitud = strlen(name);

  for (int i = 0; i < longitud; i++) {
  	printf("--- %d-%c ---\n",i, name[i]);
  }

  return 0;
}