#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_ITEMS 100
#define MAX_KEY_LEN 50

typedef struct {
	char key[MAX_KEY_LEN];
	int value;
} Item;

typedef struct {
	Item items[MAX_ITEMS];
	int size;
} Dict;

void set(Dict *dict, char *key, int value) {

	if (*dict.size == MAX_ITEMS) return;

	

}

char *my_strcpy(char *dest, const char *src) {

	char *start = dest;

	while(*src) {

		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return start;

}

char *my_strcat(const char *s1, const char *s2) {

	char *s3;

	char *start = s3;

	while(*s1) {
		*s3 = *s1;
		s1++;
		s3++;
	}

	while(*s2) {
		*s3 = *s2;
		s2++;
		s3++;
	}

	*s3 = '\0';

	return start;

}

int STD_OUT = 1;

int str_len(const char *s) {

	int len = 0; 

	while(*s) {
		s++;
		len++;
	}

	return len;

}

void leer_escribir() {

	char buf[100];
	int n = read(0, buf, 100);
	write(1, buf, n);

}

void pruebas() {
	int x = 0x250;

	char dest[20] = "hola";
	char src[] = "holdfadfa"; 

	printf("%d", str_len("hola"));

	write(STD_OUT, src, 5);

	write(STD_OUT, "\n", 1);

	printf("%zu\n", strlen(src));

	my_strcpy(dest, src);

	char *res = my_strcat(dest, src);
	char *c = strchr("destsdf", 'f');

	c++;

	printf("%d", *c == '\0');
}

void leer_escribir_torcido() {

	char buf[255];
	char w_buf[255];

	int n = read(0, buf, 255);
	int i = 0, j = 0, w_pos = 0;

	while(i < n) {

		if ( buf[i] == ' ' || buf[i] == '\n') {
			w_buf[w_pos++] = buf[i++];
		} else {

			j = i;

			while ( j < n && buf[j] != ' ' && buf[j] != '\n') j++;

			for ( int t = j - 1; t >= i; t--) {
				w_buf[w_pos++] = buf[t];
			}

			i=j;
		}
		
	}

	write(1, w_buf, n);

}

void contar_vocales() {

	char buf[255];
	int n = read(0, buf, 255);
	int i = 0;

	int vocales[5] = {0};

	while(i < n) {

	    if (buf[i] == 'a' || buf[i] == 'A') {
	        vocales[0]++;
	    } 
	    else if (buf[i] == 'e' || buf[i] == 'E') {
	        vocales[1]++;
	    } 
	    else if (buf[i] == 'i' || buf[i] == 'I') {
	        vocales[2]++;
	    } 
	    else if (buf[i] == 'o' || buf[i] == 'O') {
	        vocales[3]++;
	    } 
	    else if (buf[i] == 'u' || buf[i] == 'U') {
	        vocales[4]++;
	    }

		i++;

	}

	i = 0;

	while (1) {

	}


}

typedef struct {
	int id;
	int age;
	char c;
} Persona;

int main() {

	int vocales[5] = {0};

	printf("%d", vocales[3]);

	return 0;

	while(1) {
		leer_escribir_torcido();
	}

}