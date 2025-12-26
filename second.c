#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_greater(int *arr, int length, int threshold);

int count_greater(int *arr, int length, int threshold) {

	int total = 0;

	for (int i = 0; i < length; i++) {
		if (*arr > threshold) total++;
		arr++;
	}

	return total;

}

int my_strcmp( const char *s1, const char *s2) {

	while( *s1 != '\0' && *s2 != '\0') {

		if ( *s1 != *s2) return *s1 - *s2;

		s1++;
		s2++;
	}

	return *s1 - *s2;

}

void reverse(int *arr, int length) {

	if ( length == 1) return;

	int *first = arr;

	for (int i = 0; i < length - 1; i++) arr++;

	int *last = arr;

	int temp; 

	for (int i = 0; i < length / 2; i++) {

		temp = *first;
		*first = *last;
		*last = temp;

		first++; 
		last--;

	}

}

void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

int* filter_even(int *arr, int length, int *out_length) {

}
 
void print_array(int *arr, int length) {

	for (int i = 0; i < length; i++) {
		printf("%d ", *arr);
		arr++;
	}

}

typedef struct {
	int id;
	float temperature;
} Sensor;

int* foo(int x) {
	static int y = 100;
	y += x; 
	return &y;
}

int main() {


	int* (*f)(int);

	f = foo;

	int *t; 

	t = foo(10);

	printf("%d\n", *t);

	foo(20);

	printf("%d\n", *t);

	Sensor s; 

	Sensor *sp = &s; 

	s.id = 1;
	s.temperature = 10.35;

	sp->id = 2;

	printf("Sensor ID: %d \n", s.id);
	printf("Sensor temperature: %.6f\n", s.temperature);

	int array[5] = { 0, 1, 5, 10, -1};

	printf("%d", count_greater(array, 5, 2));

	printf("%d", my_strcmp("hola", "holacbuenos dias"));

	printf("\n");

	reverse(array, 5);

	print_array(array, 5);

	int a = 5, b = 3; 

	int (*p)[5]; 

	p = &array;

	swap(&a, &b);

	printf("a = %d, b = %d, tamano int = %d", a, b, sizeof(int));

	return 0;
}