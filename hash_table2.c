#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define HASH_SIZE 8

typedef struct HashNode {
	int value;
	struct HashNode *next;
} HashNode;

typedef struct HashTable {
	HashNode **buckets;
	int size;
	int count;
}

// Hash functions
unsigned int hashFuncModule(int value);
unsigned int hashFunc(int value);
unsigned int hashFuncMult(int value);
unsigned int hashFuncSquare(int value);
unsigned int hashFuncBits(int value);
unsigned int hashFuncBitMixing(int value);
unsigned int hashFuncStrings(const char* str);

// Core hash table operations
int  hashContains(int value);
void hashInsert(int value);
void hashRemove(int value);
void hashClear();
void hashPrint();
HashNode* hashSearch(int value);

// Hash table utilities
int    hashSize();
double hashLoadFactor();
int    hashMaxBucketLength();
double hashAvgBucketLength();
void   resize();
void hashForEach();

int current_size = HASH_SIZE;
int element_count = 0;

HashNode **hash = NULL;

//Método del modulo
unsigned int hashFuncModule(int value) {
	return (unsigned int)value % current_size;
}

//hash func generico
unsigned int hashFunc(int value) {
	return hashFuncModule(value);
}

//Método de la multiplicación
unsigned int hashFuncMult(int value) {
    const double A = 0.6180339887; // constante de Knuth
    return (unsigned int)(current_size * fmod(value * A, 1.0));
}

//Método del cuadrado medio
unsigned int hashFuncSquare(int value) {
    unsigned int square = value * value;
    return (square >> 8) % current_size;
}

//Desplazamiento de bits
unsigned int hashFuncBits(int value) {
    return ((value >> 4) ^ value) % current_size;
}

//Método Bit Mixing
unsigned int hashFuncBitMixing(int value) {
    unsigned int x = (unsigned int)value;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % current_size;
}

unsigned int hashFuncStrings(const char* str) {
    unsigned int hash = 5381;
    while (*str)
        hash = ((hash << 5) + hash) + *str++; // djb2
    return hash % current_size;
}


int hashContains(int value) {
    unsigned int h = hashFunc(value);
    HashNode *node = hash[h];

    while (node) {
        if (node->value == value)
            return 1;  // encontrado
        node = node->next;
    }
    return 0;  // no encontrado
}

void hashInsert(int value) {

	if ( hashLoadFactor() > 0.70 ) {
		resize();
	}

    unsigned int h = hashFunc(value);
    HashNode *node = malloc(sizeof(HashNode));
    node->value = value;
    node->next = hash[h];
    hash[h] = node;  // insertamos al principio del bucket
    element_count += 1;
    
}

// Redimensionamos el array si superamos el factor de carga de 0.75
void resize() {

	printf("Resizing table from %d to %d\n", current_size, current_size * 2);

	HashNode **old_table = hash;
	current_size *= 2;
	element_count = 0;

	hash = calloc(current_size, sizeof(HashNode));

	//eliminar ( free ) tabla anterior y guardar numeros en la anterior 
	for ( int i = 0; i < current_size / 2; i++) {

		if (old_table[i]) {

			// Guardamos el current 
			HashNode *current = old_table[i];

			while ( current ) {

				HashNode *aux = current;
				hashInsert(current->value);
				current = current->next;
				free(aux);

			}

		}

	}

	free(old_table);

}


int hashSize() {

	int counter = 0;
	for (int i = 0; i < current_size; i++) {

		if (hash[i]) {

			HashNode *node = hash[i];
			while (node) {
				counter += 1;
				node = node->next;
			}

		}

	}

	return counter;

}

void hashRemove(int value) {

	unsigned int h = hashFunc(value);
	HashNode **node = &hash[h];

	while ( *node ) {

		if ( (*node)->value == value ) {
			HashNode *aux = *node;
			*node = (*node)->next;
			free(aux);
			element_count--;
			return;
		}

		node = &(*node)->next;
	}

}

void hashPrint() {

	for (int i = 0; i < current_size; i++) {

		if (hash[i]) {

			printf("Bucket %d = \t", i);

			HashNode *node = hash[i];

			while ( node ) {


				printf("%d -> ", node->value);
				node = node->next;

			}

			printf("NULL \n");

		}

	}

}

void hashClear() {

	for (int i = 0; i < current_size; i++) {

		if (hash[i]) {

			HashNode *node = hash[i];

			while ( node ) {

				HashNode *aux = node;
				node = node->next;
				free(aux);

			}

		}

	}

}

void hashForEach(void (*func)(int value)) {
    for (int i = 0; i < current_size; i++) {
        HashNode *node = hash[i];
        while (node) {
            func(node->value);
            node = node->next;
        }
    }
}

//Buscamos un valor en el hash table
HashNode* hashSearch(int value) {

	int h = hashFunc(value);

	HashNode *node = hash[h];

	while( node ) {

		if ( node->value == value ) {

			return node;

		}

	}

	return NULL;

} 

double hashLoadFactor() {
    return (double)hashSize() / current_size;
}

int hashMaxBucketLength() {
    int max = 0;
    for (int i = 0; i < current_size; i++) {
        int count = 0;
        HashNode *node = hash[i];
        while (node) {
            count++;
            node = node->next;
        }
        if (count > max) max = count;
    }
    return max;
}

void test1_resize() {

	for (int i = 0; i < 7; i++) {
		printf("Insertando el numero %d\n", i);
		hashInsert(i);
	}

	hashPrint();

	for (int i = 0; i < 7; i++) {
	    if (!hashSearch(i)) {
	        printf("ERROR: %d not found\n", i);
	    }
	}

}

void test2_resize() {

	int values[] = { 0, 8, 16, 32, 64 };

	for (int i = 0; i < 5; i++) {
		hashInsert(values[i]);
	}

	hashPrint();

}

void test1_remove() {

}

double hashAvgBucketLength() {

	double total = 0;

	for ( int i = 0; i < current_size; i++) {

		HashNode *node = hash[i];

		while ( node ) {

			total++;
			node = node->next;

		}

	}

	return total / (double) current_size;

}

void hashDestroy() {
    hashClear();
    free(hash);
    hash = NULL;
    element_count = 0;
    current_size = 0;
}


int main(void) {

	hash = calloc(current_size, sizeof(HashNode*));

	hashInsert(2 + HASH_SIZE);
	hashInsert(2 + HASH_SIZE*2);

	test2_resize();

	printf("Element count: %d | Load factor: %.2f\n",
       element_count,
       (double)element_count / current_size);

	double avg = hashAvgBucketLength();

	printf("Average bucket size: %f", avg);

	hashDestroy();

	return 0;

}