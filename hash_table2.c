#include "stdio.h"
#include "stdlib.h"

#define HASH_SIZE 1024

typedef struct HashNode {
	int value;
	struct HashNode *next;
} HashNode;

HashNode *hash[HASH_SIZE] = {0};

unsigned int hashFunc(int value) {
	return (unsigned int)value % HASH_SIZE;
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
    unsigned int h = hashFunc(value);
    HashNode *node = malloc(sizeof(HashNode));
    node->value = value;
    node->next = hash[h];
    hash[h] = node;  // insertamos al principio del bucket
}

int hashSize() {

	int counter = 0;
	for (int i = 0; i < HASH_SIZE; i++) {

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

	while ( node ) {

		if ( (*node)->value == value ) {
			HashNode *aux = *node;
			*node = (*node)->next;
			free(aux);
		}

		node = &(*node)->next;
	}

}

void hashPrint() {

	for (int i = 0; i < HASH_SIZE; i++) {

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

}

int main(void) {

	printf("%u\n", (unsigned int)-3);

	hashInsert(2);
	hashInsert(3);
	hashInsert(10000);
	hashInsert(2 + HASH_SIZE);
	hashInsert(2 + HASH_SIZE*2);

	int size = hashSize();

	printf("%d\n", size);

	hashPrint();

	return 0;

}