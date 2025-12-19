#include <unistd.h>
#include <stdio.h>

int my_getline(char *buf, int max);

int my_getline(char *buf, int max) {

	char c;
	int i = 0;

	while( i < max - 1) {
		int n = read(0, &c, 1);

		if (n <= 0) break;

		buf[i++] = c;

		if ( c == '\n') break;

	}

	buf[i] = '\0';

	return i;

}

void printBits(unsigned int x) {

	for (int i = sizeof(x)*8 - 1; i >= 0; i--) {
		char t = ((x >> i) & 1) + '0';
		write(1, &t, 1);
	}

	write(1, "\n", 1);

}

void contar_bits_1(unsigned char x) {
	
}

void putRemoveBits() {

}

int main() {

	char msg[100];

	unsigned int x = 133 << 20;
	unsigned int y = 120;

	unsigned int z = x | y;

	printBits(x);
	printBits(y);
	printBits(z);

	printf("%u\n", x);

	printBits(x);

	printf("\n");

	return 0;

	int q = my_getline(msg, 50);

	write(1, "Has escrito: ", 13);

	write(1, msg, q);

	return 0;

	char c;

	do {
		read(0, &c, 1);
	} while( c != '\n');

	return 0;

	int n = read(0, msg, 100);

	write(1, msg, n);

	return 0;

}