#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int print_variable_size() {
	
}

int main() {

	uint8_t x8 = 10;

	uint16_t x16 = 20;

	uint32_t x32 = 30;

	uint64_t x64 = 40;

	printf("esto es x = %x \n", x8);

	printf("%zu\n", sizeof(__typeof__(x8)));

	printf("%zu\n", sizeof(__typeof__(x16)));

	printf("%zu\n", sizeof(__typeof__(x32)));

	printf("%zu\n", sizeof(__typeof__(x64)));

	int *p = malloc(10 * sizeof(uint8_t));

	*p = 10;

	p = malloc(5 * sizeof(int));

	*p = 10;

	printf("%d %d", *p, '\0' == 0);

	free(p);

}